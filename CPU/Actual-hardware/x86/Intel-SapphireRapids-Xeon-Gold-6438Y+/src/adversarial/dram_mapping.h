#ifndef DRAM_MAPPING_H
#define DRAM_MAPPING_H

#include <stdint.h>
#include <immintrin.h>  /* _pext_u64 (BMI2) */

/*
 * DRAM address mapping for this platform.
 *
 * Each field (ch, slot, sc, rk, bg, bank) is determined by N XOR functions.
 * Function i: bit_i = parity(physAddr & masks[i]).
 * Result = bit_0 | (bit_1 << 1) | ... | (bit_{N-1} << (N-1)).
 *
 * row and col are extracted with _pext_u64(physAddr, mask).
 *
 * Set masks to 0x0 (or empty array) for unused/single-value fields.
 * Number of mask entries == number of bits for that field.
 *
 * TODO: fill in the actual masks for the target platform by reverse-engineering
 * the memory controller (e.g., via rowhammer or DRAM Buster tooling).
 */

typedef struct {
    int ch, slot, sc, rk, bg, bank;
    int row, col;
} BankInfo;

/* Target bank: all fields must equal TARGET_* for an address to be selected. */
#define TARGET_CH    0
#define TARGET_SLOT  0
#define TARGET_SC    0
#define TARGET_RK    0
#define TARGET_BG    0
#define TARGET_BANK  0

/* ---------------------------------------------------------------------------
 * Platform masks — TODO: replace 0x0 placeholders with real values.
 * ---------------------------------------------------------------------------
 * Example layout for DDR5 1ch/1slot/2sc/1rk/8bg/4bank:
 *   ch    : 0 entries  (single channel → always 0)
 *   slot  : 0 entries  (single DIMM    → always 0)
 *   sc    : 1 entry    (1-bit sub-channel selector)
 *   rk    : 0 entries  (single rank    → always 0)
 *   bg    : 3 entries  (3-bit bank group)
 *   bank  : 2 entries  (2-bit bank within group)
 *   row   : contiguous bit-mask (e.g. bits [33:17] for typical DDR5)
 *   col   : contiguous bit-mask (e.g. bits [13:6]  = cache-line column)
 */

static const uint64_t g_ch_masks[]     = { 0x0 };
static const uint64_t g_slot_masks[]   = { 0x0 };
static const uint64_t g_sub_ch_masks[] = { 0x40 };
static const uint64_t g_rank_masks[]   = { 0x80 };
static const uint64_t g_bg_masks[]     = { 0x10000100, 0x20000200, 0x100001400 };
static const uint64_t g_bank_masks[]   = { 0x40000800, 0x80001000 };

static const uint64_t g_row_mask = 0xffff00000;
static const uint64_t g_col_mask = 0xfe000;

/* Apply N XOR functions defined by masks[0..n-1] to physAddr. */
static inline int applyXorFunctions(uint64_t physAddr,
                                    const uint64_t *masks, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (__builtin_parityl(physAddr & masks[i]))
            result |= (1 << i);
    }
    return result;
}

static inline BankInfo getBankFromPhysicalAddr(uint64_t physAddr)
{
    BankInfo info;
    info.ch   = applyXorFunctions(physAddr, g_ch_masks,
                                  (int)(sizeof(g_ch_masks)   / sizeof(g_ch_masks[0])));
    info.slot = applyXorFunctions(physAddr, g_slot_masks,
                                  (int)(sizeof(g_slot_masks) / sizeof(g_slot_masks[0])));
    info.sc   = applyXorFunctions(physAddr, g_sub_ch_masks,
                                  (int)(sizeof(g_sub_ch_masks) / sizeof(g_sub_ch_masks[0])));
    info.rk   = applyXorFunctions(physAddr, g_rank_masks,
                                  (int)(sizeof(g_rank_masks) / sizeof(g_rank_masks[0])));
    info.bg   = applyXorFunctions(physAddr, g_bg_masks,
                                  (int)(sizeof(g_bg_masks)   / sizeof(g_bg_masks[0])));
    info.bank = applyXorFunctions(physAddr, g_bank_masks,
                                  (int)(sizeof(g_bank_masks) / sizeof(g_bank_masks[0])));
    info.row  = (int)_pext_u64(physAddr, g_row_mask);
    info.col  = (int)_pext_u64(physAddr, g_col_mask);
    return info;
}

static inline int is_target_bank(const BankInfo *b)
{
    return b->ch   == TARGET_CH   &&
           b->slot == TARGET_SLOT &&
           b->sc   == TARGET_SC   &&
           b->rk   == TARGET_RK   &&
           b->bg   == TARGET_BG   &&
           b->bank == TARGET_BANK;
}

#endif /* DRAM_MAPPING_H */
