/*
 * adversarial_mpi.c — MPI-based adversarial traffic generator.
 *
 * Every MPI rank targets the SAME single DRAM bank (ch=slot=sc=rk=bg=bank=0)
 * and accesses it in a row-miss sequence:
 *   row n  col 0 -> row n+1 col 0 -> ... -> row m col 0 ->
 *   row n  col 1 -> row n+1 col 1 -> ...
 *
 * Setup:
 *   1. Allocate PAGES_PER_RANK × 1GB hugepages (mandatory; aborts otherwise).
 *   2. Look up physical base address via /proc/self/pagemap.
 *   3. Scan at 64B granularity; collect addresses whose DRAM bank == target.
 *   4. Sort collected addresses by (col, row) to enforce row-miss order.
 *   5. clflushopt every collected address, then mfence.
 *   6. Access loop: call ADVERSARIAL_update_R(slice, pause, sink) forever.
 *
 * CLI: -r <rd_percentage (even, 0-100)>  -p <pause (>= 0)>
 * Same interface as stream_mpi and random_mpi so terminate_stream works
 * without modification.
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <immintrin.h>  /* _mm_clflushopt, _mm_mfence, _pext_u64 */
#include <mpi.h>

#include "../stream_mpi/src/mess_alloc_mpi.h"
#include "dram_mapping.h"
#include "pagemap.h"
#include "adversarial_update.h"

/* Per-rank working set: number of 1GB hugepages. Increase to stress more rows. */
#define PAGES_PER_RANK 1

#define PAGE_1GB (1ULL << 30)

/* Accesses per update-function call (must match gen_adversarial_update.py). */
#define ACCESSES_PER_CALL 100

/* -------------------------------------------------------------------------
 * Address collection: (physical addr, virtual ptr, row, col) tuple
 * ------------------------------------------------------------------------- */
typedef struct {
    volatile uint64_t *vptr;
    int row;
    int col;
} TargetEntry;

static int cmp_target(const void *a, const void *b)
{
    const TargetEntry *ta = (const TargetEntry *)a;
    const TargetEntry *tb = (const TargetEntry *)b;
    if (ta->col != tb->col) return ta->col - tb->col;
    return ta->row - tb->row;
}

/* -------------------------------------------------------------------------
 * Usage / CLI
 * ------------------------------------------------------------------------- */
static void print_usage(const char *prog)
{
    fprintf(stderr,
            "Usage: %s -r <rd_percentage> -p <pause>\n"
            "  rd_percentage: even integer in [0, 100]\n"
            "  pause:         non-negative integer\n", prog);
}

/* -------------------------------------------------------------------------
 * main
 * ------------------------------------------------------------------------- */
int main(int argc, char **argv)
{
    int rd_percentage = 50;
    int pause_val = 0;
    int myrank, numranks;
    int opt;

    int rc = MPI_Init(NULL, NULL);
    if (rc != MPI_SUCCESS) {
        fprintf(stderr, "ERROR: MPI_Init failed (%d)\n", rc);
        return 1;
    }
    MPI_Comm_size(MPI_COMM_WORLD, &numranks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    /* --- parse arguments --- */
    while ((opt = getopt(argc, argv, ":r:p:")) != -1) {
        switch (opt) {
        case 'r':
            rd_percentage = atoi(optarg);
            if (rd_percentage < 0 || rd_percentage > 100 ||
                rd_percentage % 2 != 0) {
                if (myrank == 0)
                    fprintf(stderr,
                            "ERROR: rd_percentage must be an even number in [0, 100]\n");
                MPI_Finalize();
                return 1;
            }
            break;
        case 'p':
            pause_val = atoi(optarg);
            if (pause_val < 0) {
                if (myrank == 0)
                    fprintf(stderr, "ERROR: pause must be non-negative\n");
                MPI_Finalize();
                return 1;
            }
            break;
        default:
            if (myrank == 0) print_usage(argv[0]);
            MPI_Finalize();
            return 1;
        }
    }
    if (optind < argc || argc != 5) {
        if (myrank == 0) print_usage(argv[0]);
        MPI_Finalize();
        return 1;
    }

    /* --- select update function --- */
    typedef void (*update_fn_t)(volatile uint64_t **, int *, volatile uint64_t *);
    update_fn_t fn = NULL;
    switch (rd_percentage) {
    case   0: fn = ADVERSARIAL_update_0;   break;
    case   2: fn = ADVERSARIAL_update_2;   break;
    case   4: fn = ADVERSARIAL_update_4;   break;
    case   6: fn = ADVERSARIAL_update_6;   break;
    case   8: fn = ADVERSARIAL_update_8;   break;
    case  10: fn = ADVERSARIAL_update_10;  break;
    case  12: fn = ADVERSARIAL_update_12;  break;
    case  14: fn = ADVERSARIAL_update_14;  break;
    case  16: fn = ADVERSARIAL_update_16;  break;
    case  18: fn = ADVERSARIAL_update_18;  break;
    case  20: fn = ADVERSARIAL_update_20;  break;
    case  22: fn = ADVERSARIAL_update_22;  break;
    case  24: fn = ADVERSARIAL_update_24;  break;
    case  26: fn = ADVERSARIAL_update_26;  break;
    case  28: fn = ADVERSARIAL_update_28;  break;
    case  30: fn = ADVERSARIAL_update_30;  break;
    case  32: fn = ADVERSARIAL_update_32;  break;
    case  34: fn = ADVERSARIAL_update_34;  break;
    case  36: fn = ADVERSARIAL_update_36;  break;
    case  38: fn = ADVERSARIAL_update_38;  break;
    case  40: fn = ADVERSARIAL_update_40;  break;
    case  42: fn = ADVERSARIAL_update_42;  break;
    case  44: fn = ADVERSARIAL_update_44;  break;
    case  46: fn = ADVERSARIAL_update_46;  break;
    case  48: fn = ADVERSARIAL_update_48;  break;
    case  50: fn = ADVERSARIAL_update_50;  break;
    case  52: fn = ADVERSARIAL_update_52;  break;
    case  54: fn = ADVERSARIAL_update_54;  break;
    case  56: fn = ADVERSARIAL_update_56;  break;
    case  58: fn = ADVERSARIAL_update_58;  break;
    case  60: fn = ADVERSARIAL_update_60;  break;
    case  62: fn = ADVERSARIAL_update_62;  break;
    case  64: fn = ADVERSARIAL_update_64;  break;
    case  66: fn = ADVERSARIAL_update_66;  break;
    case  68: fn = ADVERSARIAL_update_68;  break;
    case  70: fn = ADVERSARIAL_update_70;  break;
    case  72: fn = ADVERSARIAL_update_72;  break;
    case  74: fn = ADVERSARIAL_update_74;  break;
    case  76: fn = ADVERSARIAL_update_76;  break;
    case  78: fn = ADVERSARIAL_update_78;  break;
    case  80: fn = ADVERSARIAL_update_80;  break;
    case  82: fn = ADVERSARIAL_update_82;  break;
    case  84: fn = ADVERSARIAL_update_84;  break;
    case  86: fn = ADVERSARIAL_update_86;  break;
    case  88: fn = ADVERSARIAL_update_88;  break;
    case  90: fn = ADVERSARIAL_update_90;  break;
    case  92: fn = ADVERSARIAL_update_92;  break;
    case  94: fn = ADVERSARIAL_update_94;  break;
    case  96: fn = ADVERSARIAL_update_96;  break;
    case  98: fn = ADVERSARIAL_update_98;  break;
    case 100: fn = ADVERSARIAL_update_100; break;
    default:
        if (myrank == 0)
            fprintf(stderr, "ERROR: no function for rd_percentage=%d\n",
                    rd_percentage);
        MPI_Finalize();
        return 1;
    }

    /* --- allocate 1GB hugepages (mandatory) --- */
    uint64_t total_bytes = (uint64_t)PAGES_PER_RANK * PAGE_1GB;
    uint64_t mmap_len = 0;
    enum mess_alloc_mode mode = MESS_ALLOC_NONE;
    void *p = NULL;

    try_mmap_single_collective(&p, total_bytes, PAGE_1GB, MAP_HUGE_1GB, "1GB",
                               &mmap_len, &mode, MPI_COMM_WORLD, myrank);

    if (p == NULL || mode == MESS_ALLOC_NONE) {
        if (myrank == 0)
            fprintf(stderr,
                    "[adversarial] FATAL: 1GB hugepage allocation failed.\n"
                    "  Ensure /sys/kernel/mm/hugepages/hugepages-1048576kB/nr_hugepages"
                    " >= %d (STREAM_CORE_COUNT x PAGES_PER_RANK).\n",
                    PAGES_PER_RANK);
        MPI_Finalize();
        return 1;
    }

    /* MAP_ANONYMOUS + MAP_POPULATE zero-fills; no memset needed. */

    /* --- obtain physical base addresses via pagemap --- */
    uint64_t phys_bases[PAGES_PER_RANK];
    pagemap_get_phys_bases(p, PAGES_PER_RANK, phys_bases);

    for (int pg = 0; pg < PAGES_PER_RANK; pg++) {
        if (phys_bases[pg] == 0) {
            fprintf(stderr,
                "[adversarial] rank %d: FATAL: phys_base[%d]=0 — "
                "pagemap PFN zeroed. Run with CAP_SYS_ADMIN (sudo).\n",
                myrank, pg);
            MPI_Finalize(); return 1;
        }
        if (phys_bases[pg] & (PAGE_1GB - 1)) {
            fprintf(stderr,
                "[adversarial] rank %d: WARNING: phys_base[%d]=0x%lx "
                "is not 1GB-aligned (unexpected for MAP_HUGE_1GB)\n",
                myrank, pg, (unsigned long)phys_bases[pg]);
            MPI_Finalize(); return 1;
        } else if (myrank == 0) {
            fprintf(stderr,
                "[adversarial] rank %d: phys_base[%d]=0x%lx OK (1GB-aligned)\n",
                myrank, pg, (unsigned long)phys_bases[pg]);
        }
    }

    /* --- scan pages at 64B granularity, collect target-bank addresses --- */
    uint64_t scan_capacity = total_bytes / 64;  /* upper bound */
    TargetEntry *candidates = (TargetEntry *)malloc(
        scan_capacity * sizeof(TargetEntry));
    if (!candidates) {
        fprintf(stderr, "[adversarial] rank %d: malloc candidates failed\n", myrank);
        MPI_Finalize();
        return 1;
    }

    uint64_t n_found = 0;
    for (int pg = 0; pg < PAGES_PER_RANK; pg++) {
        uint64_t vbase_pg = (uint64_t)p + (uint64_t)pg * PAGE_1GB;
        uint64_t phys_base = phys_bases[pg];

        for (uint64_t off = 0; off < PAGE_1GB; off += 64) {
            uint64_t phys = phys_base + off;
            BankInfo bi = getBankFromPhysicalAddr(phys);
            if (is_target_bank(&bi)) {
                candidates[n_found].vptr =
                    (volatile uint64_t *)(vbase_pg + off);
                candidates[n_found].row = bi.row;
                candidates[n_found].col = bi.col;
                n_found++;
            }
        }
    }

    if (myrank == 0)
        fprintf(stderr,
                "[adversarial] rank %d: found %lu target-bank addresses"
                " (rd=%d pause=%d)\n",
                myrank, (unsigned long)n_found, rd_percentage, pause_val);

    if (n_found < (uint64_t)ACCESSES_PER_CALL) {
        fprintf(stderr,
                "[adversarial] rank %d: FATAL: only %lu target addresses found,"
                " need at least %d. Check dram_mapping.h masks.\n",
                myrank, (unsigned long)n_found, ACCESSES_PER_CALL);
        free(candidates);
        mess_free(p, mmap_len, mode);
        MPI_Finalize();
        return 1;
    }

    /* --- sort by (col ASC, row ASC) to enforce row-miss access order ---
     * Sequential traversal gives: row n col 0 -> row n+1 col 0 -> ...
     * -> row m col 0 -> row n col 1 -> row n+1 col 1 -> ...
     * Consecutive accesses always target different rows => row miss every time.
     */
    qsort(candidates, (size_t)n_found, sizeof(TargetEntry), cmp_target);

    /* Build flat pointer array for the update functions. */
    volatile uint64_t **target_addrs =
        (volatile uint64_t **)malloc(n_found * sizeof(volatile uint64_t *));
    if (!target_addrs) {
        fprintf(stderr, "[adversarial] rank %d: malloc target_addrs failed\n",
                myrank);
        free(candidates);
        mess_free(p, mmap_len, mode);
        MPI_Finalize();
        return 1;
    }
    for (uint64_t i = 0; i < n_found; i++)
        target_addrs[i] = candidates[i].vptr;
    free(candidates);

    /* --- flush all target cache lines once before the main loop --- */
    for (uint64_t i = 0; i < n_found; i++)
        _mm_clflushopt((void *)target_addrs[i]);
    _mm_mfence();

    fprintf(stderr, "[adversarial] rank %d ready. Starting access loop.\n",
            myrank);

    /* --- main access loop --- */
    uint64_t idx = 0;
    volatile uint64_t sink = 0;

    while (1) {
        /* Wrap index so the next 100 entries are always valid. */
        if (idx + ACCESSES_PER_CALL > n_found)
            idx = 0;
        fn(target_addrs + idx, &pause_val, &sink);
        idx += ACCESSES_PER_CALL;
    }

    /* unreachable */
    fprintf(stderr, "sink=%lu\n", (unsigned long)sink);
    free(target_addrs);
    mess_free(p, mmap_len, mode);
    MPI_Finalize();
    return 0;
}
