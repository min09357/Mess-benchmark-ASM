#ifndef PAGEMAP_H
#define PAGEMAP_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * Read the physical base address of a 1GB hugepage whose virtual base is vbase.
 *
 * 1GB hugepages are physically contiguous, so knowing the physical address of
 * the first 4KB frame is sufficient: for any offset off in [0, 1GB),
 *     phys(vbase + off) = phys_base + off
 *
 * Requires /proc/self/pagemap to be readable (needs CAP_SYS_ADMIN on Linux
 * 4.0+, or perf_event_paranoid=-1 environment which this benchmark already
 * requires). Pages must be present (MAP_POPULATE on mmap guarantees this).
 */
static inline uint64_t pagemap_get_phys_base(void *vbase)
{
    int fd = open("/proc/self/pagemap", O_RDONLY);
    if (fd < 0) {
        perror("open /proc/self/pagemap");
        exit(1);
    }

    uint64_t vpn = (uint64_t)vbase >> 12;
    uint64_t entry = 0;
    ssize_t n = pread(fd, &entry, sizeof(entry), (off_t)(vpn * sizeof(entry)));
    close(fd);

    if (n != (ssize_t)sizeof(entry)) {
        fprintf(stderr, "pagemap: short read at vpn=%lu\n", (unsigned long)vpn);
        exit(1);
    }
    if (!(entry >> 63)) {
        fprintf(stderr, "pagemap: page not present at vbase=%p\n", vbase);
        exit(1);
    }

    uint64_t pfn = entry & ((1ULL << 55) - 1);
    return pfn << 12;
}

/*
 * Read physical bases for n_pages consecutive 1GB-aligned hugepages starting
 * at vbase. out_phys_bases must have room for n_pages uint64_t values.
 */
static inline void pagemap_get_phys_bases(void *vbase, int n_pages,
                                          uint64_t *out_phys_bases)
{
    int fd = open("/proc/self/pagemap", O_RDONLY);
    if (fd < 0) {
        perror("open /proc/self/pagemap");
        exit(1);
    }

    for (int i = 0; i < n_pages; i++) {
        uint64_t va = (uint64_t)vbase + (uint64_t)i * (1ULL << 30);
        uint64_t vpn = va >> 12;
        uint64_t entry = 0;
        ssize_t n = pread(fd, &entry, sizeof(entry),
                          (off_t)(vpn * sizeof(entry)));
        if (n != (ssize_t)sizeof(entry)) {
            fprintf(stderr, "pagemap: short read at page %d\n", i);
            close(fd);
            exit(1);
        }
        if (!(entry >> 63)) {
            fprintf(stderr, "pagemap: page %d not present\n", i);
            close(fd);
            exit(1);
        }
        uint64_t pfn = entry & ((1ULL << 55) - 1);
        out_phys_bases[i] = pfn << 12;
    }

    close(fd);
}

#endif /* PAGEMAP_H */
