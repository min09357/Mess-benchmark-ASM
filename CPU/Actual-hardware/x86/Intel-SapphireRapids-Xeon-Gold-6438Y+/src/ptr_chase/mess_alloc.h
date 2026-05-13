#ifndef MESS_ALLOC_H
#define MESS_ALLOC_H

#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

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

/* Try to allocate `bytes` via mmap with the given huge-page flag.
 *
 * On success: stores pointer in *out_p, mmap length (rounded up to page_size)
 *             in *out_mmap_len, and resolved mode in *out_mode. Logs to stderr.
 * On failure: leaves all outputs untouched so the caller's if-chain falls
 *             through to the next tier.
 *
 * Caller pattern (each tier is one commentable line):
 *     if (mode == MESS_ALLOC_NONE) try_mmap_huge(...);
 */
static inline void try_mmap_huge(void **out_p,
                                 uint64_t bytes,
                                 uint64_t page_size,
                                 int huge_flag,
                                 const char *size_label,
                                 uint64_t *out_mmap_len,
                                 enum mess_alloc_mode *out_mode,
                                 const char *who)
{
    uint64_t len = (bytes + page_size - 1) & ~(page_size - 1);
    void *p = mmap(NULL, len, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB | huge_flag,
                   -1, 0);
    if (p == MAP_FAILED) {
        fprintf(stderr, "[%s] %s-hugepage mmap failed: %s\n",
                who, size_label, strerror(errno));
        return;
    }
    *out_p = p;
    *out_mmap_len = len;
    *out_mode = (huge_flag == MAP_HUGE_1GB) ? MESS_ALLOC_1GB : MESS_ALLOC_2MB;
    fprintf(stderr, "[%s] %s-hugepage, %lu bytes\n", who, size_label, len);
}

/* Final fallback using posix_memalign. Sets *out_p to NULL on failure. */
static inline void try_posix(void **out_p,
                             uint64_t bytes,
                             size_t align,
                             enum mess_alloc_mode *out_mode,
                             const char *who)
{
    int r = posix_memalign(out_p, align, bytes);
    if (r != 0) {
        fprintf(stderr, "[%s] posix_memalign failed: %s\n", who, strerror(r));
        *out_p = NULL;
        return;
    }
    *out_mode = MESS_ALLOC_POSIX;
    fprintf(stderr, "[%s] posix_memalign (4KB pages), %lu bytes\n", who, bytes);
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

#endif /* MESS_ALLOC_H */
