#ifndef MESS_ALLOC_MPI_H
#define MESS_ALLOC_MPI_H

#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <mpi.h>

#ifndef MAP_HUGE_SHIFT
#define MAP_HUGE_SHIFT 26
#endif
#ifndef MAP_HUGE_2MB
#define MAP_HUGE_2MB (21 << MAP_HUGE_SHIFT)
#endif
#ifndef MAP_HUGE_1GB
#define MAP_HUGE_1GB (30 << MAP_HUGE_SHIFT)
#endif

enum mess_alloc_mode {
    MESS_ALLOC_NONE = 0,
    MESS_ALLOC_POSIX,
    MESS_ALLOC_2MB,
    MESS_ALLOC_1GB
};

/* Collective MPI version: every rank attempts to mmap two arrays (a, b) using the
 * given huge-page flag. An MPI_Allreduce(MIN) on the local success flag enforces
 * all-or-nothing across ranks, so the per-rank allocation paths cannot diverge
 * (avoids mixing huge-page and 4KB ranks in a single measurement).
 *
 * On all-success: writes pointers, lengths, and modes for both a and b; logs from rank 0.
 * On any-failure: any locally successful mmap is munmap'd; outputs left untouched
 *                 so the caller's if-chain can try the next tier.
 *
 * Caller pattern (each tier is one commentable line):
 *     if (mode_a == MESS_ALLOC_NONE) try_mmap_pair_collective(...);
 */
static inline void try_mmap_pair_collective(void **out_a, void **out_b,
                                            uint64_t bytes,
                                            uint64_t page_size,
                                            int huge_flag,
                                            const char *size_label,
                                            uint64_t *out_len_a,
                                            uint64_t *out_len_b,
                                            enum mess_alloc_mode *out_mode_a,
                                            enum mess_alloc_mode *out_mode_b,
                                            MPI_Comm comm,
                                            int myrank)
{
    uint64_t len = (bytes + page_size - 1) & ~(page_size - 1);

    void *ta = mmap(NULL, len, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB | MAP_POPULATE | huge_flag,
                    -1, 0);
    void *tb = mmap(NULL, len, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB | MAP_POPULATE | huge_flag,
                    -1, 0);

    int local_ok = (ta != MAP_FAILED && tb != MAP_FAILED) ? 1 : 0;
    int all_ok = 0;
    MPI_Allreduce(&local_ok, &all_ok, 1, MPI_INT, MPI_MIN, comm);

    if (all_ok) {
        *out_a = ta;
        *out_b = tb;
        *out_len_a = len;
        *out_len_b = len;
        enum mess_alloc_mode m = (huge_flag == MAP_HUGE_1GB) ? MESS_ALLOC_1GB : MESS_ALLOC_2MB;
        *out_mode_a = m;
        *out_mode_b = m;
        if (myrank == 0) {
            fprintf(stderr,
                    "[stream] all ranks got %s-hugepage (%lu bytes per array)\n",
                    size_label, len);
        }
    } else {
        /* Undo any partial local success so the pages return to the pool before
         * the next tier or the posix fallback runs. */
        if (ta != MAP_FAILED) munmap(ta, len);
        if (tb != MAP_FAILED) munmap(tb, len);
        if (myrank == 0) {
            fprintf(stderr,
                    "[stream] %s-hugepage failed on at least one rank, falling through\n",
                    size_label);
        }
    }
}

/* Final fallback for the pair (a, b). Always sets *out_mode_* on success. */
static inline void try_posix_pair(void **out_a, void **out_b,
                                  uint64_t bytes,
                                  size_t align,
                                  enum mess_alloc_mode *out_mode_a,
                                  enum mess_alloc_mode *out_mode_b,
                                  int myrank)
{
    int ra = posix_memalign(out_a, align, bytes);
    int rb = posix_memalign(out_b, align, bytes);
    if (ra != 0 || rb != 0) {
        if (myrank == 0) {
            fprintf(stderr,
                    "[stream] posix_memalign failed (a=%d, b=%d)\n", ra, rb);
        }
        if (ra == 0) { free(*out_a); *out_a = NULL; }
        if (rb == 0) { free(*out_b); *out_b = NULL; }
        return;
    }
    *out_mode_a = MESS_ALLOC_POSIX;
    *out_mode_b = MESS_ALLOC_POSIX;
    if (myrank == 0) {
        fprintf(stderr,
                "[stream] posix_memalign (4KB pages), %lu bytes per array\n",
                bytes);
    }
}

/* Collective hugepage attempt for a single buffer.
 * All-or-nothing via MPI_Allreduce(MIN): if any rank fails, all ranks release
 * the mapping and fall through to the next tier.
 *
 * Caller pattern (each tier is one commentable line):
 *     if (mode == MESS_ALLOC_NONE) try_mmap_single_collective(...);
 */
static inline void try_mmap_single_collective(void **out_p,
                                              uint64_t bytes,
                                              uint64_t page_size,
                                              int huge_flag,
                                              const char *size_label,
                                              uint64_t *out_len,
                                              enum mess_alloc_mode *out_mode,
                                              MPI_Comm comm,
                                              int myrank)
{
    uint64_t len = (bytes + page_size - 1) & ~(page_size - 1);

    void *tp = mmap(NULL, len, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB | MAP_POPULATE | huge_flag,
                    -1, 0);

    int local_ok = (tp != MAP_FAILED) ? 1 : 0;
    int all_ok = 0;
    MPI_Allreduce(&local_ok, &all_ok, 1, MPI_INT, MPI_MIN, comm);

    if (all_ok) {
        *out_p = tp;
        *out_len = len;
        enum mess_alloc_mode m = (huge_flag == MAP_HUGE_1GB) ? MESS_ALLOC_1GB : MESS_ALLOC_2MB;
        *out_mode = m;
        if (myrank == 0) {
            fprintf(stderr,
                    "[random] all ranks got %s-hugepage (%lu bytes per table)\n",
                    size_label, len);
        }
    } else {
        if (tp != MAP_FAILED) munmap(tp, len);
        if (myrank == 0) {
            fprintf(stderr,
                    "[random] %s-hugepage failed on at least one rank, falling through\n",
                    size_label);
        }
    }
}

/* posix_memalign fallback for a single buffer.
 * Caller must memset() to zero if needed (posix_memalign does not zero-fill). */
static inline void try_posix_single(void **out_p,
                                    uint64_t bytes,
                                    size_t align,
                                    enum mess_alloc_mode *out_mode,
                                    int myrank)
{
    int r = posix_memalign(out_p, align, bytes);
    if (r != 0) {
        if (myrank == 0) {
            fprintf(stderr, "[random] posix_memalign failed (%d)\n", r);
        }
        *out_p = NULL;
        return;
    }
    *out_mode = MESS_ALLOC_POSIX;
    if (myrank == 0) {
        fprintf(stderr,
                "[random] posix_memalign (4KB pages), %lu bytes per table\n",
                bytes);
    }
}

/* Release memory regardless of how it was allocated. */
static inline void mess_free(void *p,
                             uint64_t mmap_len,
                             enum mess_alloc_mode mode)
{
    if (!p) return;
    if (mode == MESS_ALLOC_POSIX) {
        free(p);
    } else if (mode == MESS_ALLOC_2MB || mode == MESS_ALLOC_1GB) {
        munmap(p, mmap_len);
    }
}

#endif /* MESS_ALLOC_MPI_H */
