/*
 * random_mpi.c -- MPI-based random-access memory traffic generator.
 *
 * Each MPI rank independently walks a 256 MB table using an LFSR-based
 * random index sequence (POLY=7, scalar equivalent of HPCC RandomAccess).
 * Read/write ratio is controlled by -r <rd_percentage> (even, 0..100).
 * Pause between access groups is controlled by -p <pause> (same as stream_mpi).
 *
 * Table allocation follows the same three-tier hugepage strategy as stream_mpi:
 *   Tier 1: 1GB hugepage (collective all-or-nothing via MPI_Allreduce)
 *   Tier 2: 2MB hugepage (collective all-or-nothing)
 *   Tier 3: posix_memalign 4KB pages (final fallback)
 */

#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <mpi.h>

#include "mess_alloc_mpi.h"
#include "random_update.h"

#define TABLE_BYTES_PER_RANK  (256ULL * 1024 * 1024)
/* #define TABLE_BYTES_PER_RANK  (1024ULL * 1024 * 1024) */  /* 1GB per-rank alternative */
#define TABLE_ELEMS  (TABLE_BYTES_PER_RANK / sizeof(uint64_t))
#define TABLE_MASK   (TABLE_ELEMS - 1ULL)

typedef void (*update_fn_t)(volatile uint64_t *, uint64_t, int *,
                            uint64_t *, volatile uint64_t *);

static void print_usage(const char *prog)
{
    fprintf(stderr, "Usage: %s -r <rd_percentage> -p <pause>\n"
            "  rd_percentage: even integer in [0, 100]\n"
            "  pause:         non-negative integer\n", prog);
}

int main(int argc, char **argv)
{
    int rd_percentage = 50;
    int pause_val = 0;
    int opt;
    int myrank, numranks;

    int rc = MPI_Init(NULL, NULL);
    if (rc != MPI_SUCCESS) {
        fprintf(stderr, "ERROR: MPI_Init failed (%d)\n", rc);
        return 1;
    }
    MPI_Comm_size(MPI_COMM_WORLD, &numranks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    while ((opt = getopt(argc, argv, ":r:p:")) != -1) {
        switch (opt) {
            case 'r':
                rd_percentage = atoi(optarg);
                if (rd_percentage < 0 || rd_percentage > 100 || rd_percentage % 2 != 0) {
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

    /* select update function for the requested read ratio */
    update_fn_t RANDOM_update_rw = NULL;
    switch (rd_percentage) {
        case   0: RANDOM_update_rw = RANDOM_update_0;   break;
        case   2: RANDOM_update_rw = RANDOM_update_2;   break;
        case   4: RANDOM_update_rw = RANDOM_update_4;   break;
        case   6: RANDOM_update_rw = RANDOM_update_6;   break;
        case   8: RANDOM_update_rw = RANDOM_update_8;   break;
        case  10: RANDOM_update_rw = RANDOM_update_10;  break;
        case  12: RANDOM_update_rw = RANDOM_update_12;  break;
        case  14: RANDOM_update_rw = RANDOM_update_14;  break;
        case  16: RANDOM_update_rw = RANDOM_update_16;  break;
        case  18: RANDOM_update_rw = RANDOM_update_18;  break;
        case  20: RANDOM_update_rw = RANDOM_update_20;  break;
        case  22: RANDOM_update_rw = RANDOM_update_22;  break;
        case  24: RANDOM_update_rw = RANDOM_update_24;  break;
        case  26: RANDOM_update_rw = RANDOM_update_26;  break;
        case  28: RANDOM_update_rw = RANDOM_update_28;  break;
        case  30: RANDOM_update_rw = RANDOM_update_30;  break;
        case  32: RANDOM_update_rw = RANDOM_update_32;  break;
        case  34: RANDOM_update_rw = RANDOM_update_34;  break;
        case  36: RANDOM_update_rw = RANDOM_update_36;  break;
        case  38: RANDOM_update_rw = RANDOM_update_38;  break;
        case  40: RANDOM_update_rw = RANDOM_update_40;  break;
        case  42: RANDOM_update_rw = RANDOM_update_42;  break;
        case  44: RANDOM_update_rw = RANDOM_update_44;  break;
        case  46: RANDOM_update_rw = RANDOM_update_46;  break;
        case  48: RANDOM_update_rw = RANDOM_update_48;  break;
        case  50: RANDOM_update_rw = RANDOM_update_50;  break;
        case  52: RANDOM_update_rw = RANDOM_update_52;  break;
        case  54: RANDOM_update_rw = RANDOM_update_54;  break;
        case  56: RANDOM_update_rw = RANDOM_update_56;  break;
        case  58: RANDOM_update_rw = RANDOM_update_58;  break;
        case  60: RANDOM_update_rw = RANDOM_update_60;  break;
        case  62: RANDOM_update_rw = RANDOM_update_62;  break;
        case  64: RANDOM_update_rw = RANDOM_update_64;  break;
        case  66: RANDOM_update_rw = RANDOM_update_66;  break;
        case  68: RANDOM_update_rw = RANDOM_update_68;  break;
        case  70: RANDOM_update_rw = RANDOM_update_70;  break;
        case  72: RANDOM_update_rw = RANDOM_update_72;  break;
        case  74: RANDOM_update_rw = RANDOM_update_74;  break;
        case  76: RANDOM_update_rw = RANDOM_update_76;  break;
        case  78: RANDOM_update_rw = RANDOM_update_78;  break;
        case  80: RANDOM_update_rw = RANDOM_update_80;  break;
        case  82: RANDOM_update_rw = RANDOM_update_82;  break;
        case  84: RANDOM_update_rw = RANDOM_update_84;  break;
        case  86: RANDOM_update_rw = RANDOM_update_86;  break;
        case  88: RANDOM_update_rw = RANDOM_update_88;  break;
        case  90: RANDOM_update_rw = RANDOM_update_90;  break;
        case  92: RANDOM_update_rw = RANDOM_update_92;  break;
        case  94: RANDOM_update_rw = RANDOM_update_94;  break;
        case  96: RANDOM_update_rw = RANDOM_update_96;  break;
        case  98: RANDOM_update_rw = RANDOM_update_98;  break;
        case 100: RANDOM_update_rw = RANDOM_update_100; break;
        default:
            if (myrank == 0)
                fprintf(stderr, "ERROR: no update function for rd_percentage=%d\n",
                        rd_percentage);
            MPI_Finalize();
            return 1;
    }

    /* allocate per-rank table using three-tier hugepage strategy */
    uint64_t bytes = TABLE_BYTES_PER_RANK;
    uint64_t mmap_len = 0;
    enum mess_alloc_mode mode = MESS_ALLOC_NONE;
    void *p = NULL;

    /* Tier 1: 1GB hugepage */
    if (mode == MESS_ALLOC_NONE)
        try_mmap_single_collective(&p, bytes, 1ULL << 30, MAP_HUGE_1GB, "1GB",
                                   &mmap_len, &mode, MPI_COMM_WORLD, myrank);
    /* Tier 2: 2MB hugepage */
    if (mode == MESS_ALLOC_NONE)
        try_mmap_single_collective(&p, bytes, 1ULL << 21, MAP_HUGE_2MB, "2MB",
                                   &mmap_len, &mode, MPI_COMM_WORLD, myrank);
    /* Tier 3: posix_memalign 4KB pages (final fallback, do not comment out) */
    if (mode == MESS_ALLOC_NONE)
        try_posix_single(&p, bytes, 64, &mode, myrank);

    if (p == NULL) {
        if (myrank == 0)
            fprintf(stderr, "[random] allocation failed (all tiers exhausted)\n");
        MPI_Finalize();
        return 1;
    }

    /* MAP_ANONYMOUS mmap paths zero-fill automatically; posix_memalign does not */
    if (mode == MESS_ALLOC_POSIX)
        memset(p, 0, bytes);

    volatile uint64_t *table = (volatile uint64_t *)p;

    /* each rank starts from a distinct seed so random walks diverge */
    uint64_t ran = (uint64_t)(myrank + 1);
    volatile uint64_t sink = 0;

    fprintf(stderr, "[random] rank %d launched (rd=%d pause=%d)\n",
            myrank, rd_percentage, pause_val);

    while (1) {
        RANDOM_update_rw(table, TABLE_MASK, &pause_val, &ran, &sink);
    }

    /* unreachable: prevent dead-code elimination of sink and table accesses */
    fprintf(stderr, "sink=%lu\n", (unsigned long)sink);
    mess_free(p, mmap_len, mode);
    MPI_Finalize();
    return 0;
}
