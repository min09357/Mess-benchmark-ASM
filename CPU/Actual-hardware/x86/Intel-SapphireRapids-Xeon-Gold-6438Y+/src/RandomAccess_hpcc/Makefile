MPICC    = mpicc
CC       = gcc
CFLAGS   = -march=native -Wall -O3
# Disable both loop and SLP vectorization so that the 100 explicit accesses
# in each RANDOM_update_R function emit 100 individual load/store instructions
# rather than being folded into packed AVX-512 operations by the compiler.
RANDUPD_CFLAGS = $(CFLAGS) -fno-tree-vectorize -fno-tree-slp-vectorize -Wno-unused-parameter
LDFLAGS  = -pthread -lrt

STREAM_SRC = ../stream_mpi/src
INCLUDES   = -I$(STREAM_SRC)

BUILDDIR = build
TARGET   = random_mpi.x

OBJS = $(BUILDDIR)/random_mpi.o \
       $(BUILDDIR)/random_update.o \
       $(BUILDDIR)/nop.o

all: init $(TARGET)

init:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/random_mpi.o: random_mpi.c random_update.h
	$(MPICC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILDDIR)/random_update.o: random_update.c random_update.h
	$(CC) $(RANDUPD_CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILDDIR)/nop.o: $(STREAM_SRC)/nop.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(MPICC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all init clean
