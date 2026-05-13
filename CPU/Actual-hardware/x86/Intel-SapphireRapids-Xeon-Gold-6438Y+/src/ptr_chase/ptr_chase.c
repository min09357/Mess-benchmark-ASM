/*
 * Copyright (c) 2024, Barcelona Supercomputing Center
 * Contact: mess             [at] bsc [dot] es
 *          pouya.esmaili    [at] bsc [dot] es
 *          petar.radojkovic [at] bsc [dot] es
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of the copyright holder nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdint> // include this header for uint64_t
#include <sys/mman.h> // for mmap

#include "perf_helper.h"
#include "mess_alloc.h"

// using namespace std;  // removed: clashes with std::array vs. our global `array` on libstdc++ 13+

#ifndef ARRAY_ELEMS
#pragma message "ARRAY_ELEMS not defined. Using the default value."
#define ARRAY_ELEMS 524288
#endif

#ifndef ITERS
// #pragma message "ITERS not defined. Using the default value."
#define ITERS 5000
#endif

#ifndef CACHE_LINE
#define CACHE_LINE 64
#endif

struct line{
    struct line *next; // 8 byte
    uint8_t pad[CACHE_LINE-8];
};


struct line *pchase_array;


int main(int argc, char *argv[]) {
    uint64_t array_bytes = ((uint64_t) ARRAY_ELEMS) * CACHE_LINE; // total array size in bytes

    /* Three-tier allocator: try 1GB hugepage, then 2MB hugepage, then plain posix.
     * Comment out any tier line to disable that page size. Tier 3 must stay active. */
    uint64_t mmap_len = 0;
    enum mess_alloc_mode mode = MESS_ALLOC_NONE;
    void *p = NULL;

    // Tier 1: 1GB hugepage
    if (mode == MESS_ALLOC_NONE) try_mmap_huge(&p, array_bytes, 1ULL << 30, MAP_HUGE_1GB, "1GB", &mmap_len, &mode, "ptr_chase");
    // Tier 2: 2MB hugepage
    if (mode == MESS_ALLOC_NONE) try_mmap_huge(&p, array_bytes, 1ULL << 21, MAP_HUGE_2MB, "2MB", &mmap_len, &mode, "ptr_chase");
    // Tier 3: posix_memalign (final fallback, do not comment out)
    if (mode == MESS_ALLOC_NONE) try_posix(&p, array_bytes, CACHE_LINE, &mode, "ptr_chase");

    if (p == NULL) {
        printf("Allocation of array failed (all tiers exhausted)\n");
        exit(1);
    }
    pchase_array = (struct line *) p;


    std::ifstream inputFile ("array.dat");
    if (!inputFile.is_open()) {
        printf("Random walk file cannot be located.\n");
        mess_free(pchase_array, mmap_len, mode);
        exit(1);
    }

    // generating input of pointer chasing...
    // insert next entry of line from the file.
    for (uint64_t i = 0; i < ARRAY_ELEMS; ++i)
    {
        uint64_t tmp;
        inputFile >> tmp;
        pchase_array[i].next = (struct line *) tmp;
    }

    // cout << "iterations are:" << ITERS << endl;
    // cout << "array elements are:" << ARRAY_ELEMS << endl;
    std::cout << "array_bytes: " << array_bytes << std::endl; 

    // if we do not need the information for tlb and etc we can just execute counter=0 (instructions and cycles)
    for (int counter = 0; counter < 2; ++counter)
    {
        
        setPerfCounters();
        initializeProfiling(counter);
        startProfiling();

        register int i asm("ecx") = ITERS;
        register struct line *start asm("rbx"); // rbx is fixed as the beginning of the array, what changes is the offset inside the array, given by rax
        start = pchase_array;
        register struct line *next asm("rax"); // rax is the next element to be read inside the array
        next = pchase_array[0].next;                  // it starts with the 64 bit information contained in the first position of the array
                                               // the 64 bit information is an offset
                                               // the assembly code copies to rax the value contained at the array position (relative)0 + 64-bit offset
                                               // then in the next step it accesses 0 + the new offset to repeat the copy.
                                               // It is being forced to perform jumps inside the array
        __asm__ __volatile__ (
            "start_loop:"
            #include "loop.h"
            "dec %ecx;"
            "jnz start_loop;"
        );

        endProfiling();
        readProfiling(counter);
    }
    readExecutionTime();

    mess_free(pchase_array, mmap_len, mode);
    printf("Done walking!\n");
    return 0;
}
