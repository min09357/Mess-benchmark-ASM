export MPICH_CC = /usr/bin/gcc

MPICC    = mpicc
CC       = gcc
CFLAGS   = -march=native -Wall -O3
# Disable vectorization on adversarial_update.c so the 100 explicit pointer
# dereferences emit 100 individual load/store instructions instead of being
# folded into gather/scatter operations.
ADVUPD_CFLAGS = $(CFLAGS) -fno-tree-vectorize -fno-tree-slp-vectorize -Wno-unused-parameter
LDFLAGS  = -pthread -lrt

STREAM_SRC = ../stream_mpi/src
INCLUDES   = -I$(STREAM_SRC)

BUILDDIR = build
TARGET   = adversarial_mpi.x

OBJS = $(BUILDDIR)/adversarial_mpi.o \
       $(BUILDDIR)/adversarial_update.o \
       $(BUILDDIR)/nop.o

all: init $(TARGET)

init:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/adversarial_mpi.o: adversarial_mpi.c adversarial_update.h \
                                dram_mapping.h pagemap.h
	$(MPICC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILDDIR)/adversarial_update.o: adversarial_update.c adversarial_update.h
	$(CC) $(ADVUPD_CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILDDIR)/nop.o: $(STREAM_SRC)/nop.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(MPICC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# Regenerate adversarial_update.c from the generator script.
# Run manually when changing ACCESSES_PER_CALL or the R/W interleave rule.
gen:
	python3 gen_adversarial_update.py

clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all init gen clean
