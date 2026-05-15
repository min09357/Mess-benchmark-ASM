/* 
 * 51 variants of RANDOM_update_R (R in {0, 2, 4, ..., 100}).
 * Each function: 100 accesses, 20 nop() calls (one after every 5 accesses).
 * LFSR step before each access: ran = (ran << 1) ^ ((int64_t)ran < 0 ? POLY : 0)
 * Optimized version: ran = (ran << 1) ^ (-(ran >> 63) & POLY)
 * Read:  local += table[ran & mask]
 * Write: table[ran & mask] = 0
 * R/W interleave: is_read[slot] = ((slot * R) % 100) < R  (read-first, exactly R reads)
 */

#include "random_update.h"

/* RANDOM_update_0: 0 read(s) + 100 write(s). */
void RANDOM_update_0(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_2: 2 read(s) + 98 write(s). */
void RANDOM_update_2(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_4: 4 read(s) + 96 write(s). */
void RANDOM_update_4(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_6: 6 read(s) + 94 write(s). */
void RANDOM_update_6(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_8: 8 read(s) + 92 write(s). */
void RANDOM_update_8(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_10: 10 read(s) + 90 write(s). */
void RANDOM_update_10(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_12: 12 read(s) + 88 write(s). */
void RANDOM_update_12(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_14: 14 read(s) + 86 write(s). */
void RANDOM_update_14(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_16: 16 read(s) + 84 write(s). */
void RANDOM_update_16(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_18: 18 read(s) + 82 write(s). */
void RANDOM_update_18(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_20: 20 read(s) + 80 write(s). */
void RANDOM_update_20(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_22: 22 read(s) + 78 write(s). */
void RANDOM_update_22(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_24: 24 read(s) + 76 write(s). */
void RANDOM_update_24(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_26: 26 read(s) + 74 write(s). */
void RANDOM_update_26(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_28: 28 read(s) + 72 write(s). */
void RANDOM_update_28(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_30: 30 read(s) + 70 write(s). */
void RANDOM_update_30(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_32: 32 read(s) + 68 write(s). */
void RANDOM_update_32(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_34: 34 read(s) + 66 write(s). */
void RANDOM_update_34(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_36: 36 read(s) + 64 write(s). */
void RANDOM_update_36(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_38: 38 read(s) + 62 write(s). */
void RANDOM_update_38(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_40: 40 read(s) + 60 write(s). */
void RANDOM_update_40(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_42: 42 read(s) + 58 write(s). */
void RANDOM_update_42(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_44: 44 read(s) + 56 write(s). */
void RANDOM_update_44(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_46: 46 read(s) + 54 write(s). */
void RANDOM_update_46(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_48: 48 read(s) + 52 write(s). */
void RANDOM_update_48(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_50: 50 read(s) + 50 write(s). */
void RANDOM_update_50(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_52: 52 read(s) + 48 write(s). */
void RANDOM_update_52(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_54: 54 read(s) + 46 write(s). */
void RANDOM_update_54(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_56: 56 read(s) + 44 write(s). */
void RANDOM_update_56(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_58: 58 read(s) + 42 write(s). */
void RANDOM_update_58(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_60: 60 read(s) + 40 write(s). */
void RANDOM_update_60(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_62: 62 read(s) + 38 write(s). */
void RANDOM_update_62(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_64: 64 read(s) + 36 write(s). */
void RANDOM_update_64(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_66: 66 read(s) + 34 write(s). */
void RANDOM_update_66(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_68: 68 read(s) + 32 write(s). */
void RANDOM_update_68(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_70: 70 read(s) + 30 write(s). */
void RANDOM_update_70(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_72: 72 read(s) + 28 write(s). */
void RANDOM_update_72(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_74: 74 read(s) + 26 write(s). */
void RANDOM_update_74(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_76: 76 read(s) + 24 write(s). */
void RANDOM_update_76(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_78: 78 read(s) + 22 write(s). */
void RANDOM_update_78(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_80: 80 read(s) + 20 write(s). */
void RANDOM_update_80(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_82: 82 read(s) + 18 write(s). */
void RANDOM_update_82(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_84: 84 read(s) + 16 write(s). */
void RANDOM_update_84(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_86: 86 read(s) + 14 write(s). */
void RANDOM_update_86(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_88: 88 read(s) + 12 write(s). */
void RANDOM_update_88(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_90: 90 read(s) + 10 write(s). */
void RANDOM_update_90(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_92: 92 read(s) + 8 write(s). */
void RANDOM_update_92(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_94: 94 read(s) + 6 write(s). */
void RANDOM_update_94(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_96: 96 read(s) + 4 write(s). */
void RANDOM_update_96(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_98: 98 read(s) + 2 write(s). */
void RANDOM_update_98(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); table[ran & mask] = 0; /* W slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

/* RANDOM_update_100: 100 read(s) + 0 write(s). */
void RANDOM_update_100(volatile uint64_t *table, uint64_t mask,
                       int *pause, uint64_t *ran_io, volatile uint64_t *sink)
{
    uint64_t ran = *ran_io;
    uint64_t local = *sink;

    /* group 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 0 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 1 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 4 */
    nop(pause);

    /* group 2 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 9 */
    nop(pause);

    /* group 3 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 14 */
    nop(pause);

    /* group 4 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 19 */
    nop(pause);

    /* group 5 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 21 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 22 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 23 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 24 */
    nop(pause);

    /* group 6 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 25 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 26 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 27 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 28 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 29 */
    nop(pause);

    /* group 7 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 30 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 31 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 32 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 33 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 34 */
    nop(pause);

    /* group 8 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 35 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 36 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 37 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 38 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 39 */
    nop(pause);

    /* group 9 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 40 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 41 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 42 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 43 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 44 */
    nop(pause);

    /* group 10 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 45 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 46 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 47 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 48 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 49 */
    nop(pause);

    /* group 11 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 50 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 51 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 52 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 53 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 54 */
    nop(pause);

    /* group 12 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 55 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 56 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 57 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 58 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 59 */
    nop(pause);

    /* group 13 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 60 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 61 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 62 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 63 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 64 */
    nop(pause);

    /* group 14 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 65 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 66 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 67 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 68 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 69 */
    nop(pause);

    /* group 15 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 70 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 71 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 72 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 73 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 74 */
    nop(pause);

    /* group 16 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 75 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 76 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 77 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 78 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 79 */
    nop(pause);

    /* group 17 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 80 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 81 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 82 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 83 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 84 */
    nop(pause);

    /* group 18 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 85 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 86 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 87 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 88 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 89 */
    nop(pause);

    /* group 19 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 90 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 91 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 92 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 93 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 94 */
    nop(pause);

    /* group 20 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 95 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 96 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 97 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 98 */
    ran = (ran << 1) ^ (-(ran >> 63) & POLY); local += table[ran & mask]; /* R slot 99 */
    nop(pause);

    *ran_io = ran;
    *sink = local;
}

