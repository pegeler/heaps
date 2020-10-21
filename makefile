CC = gcc -O2

.PHONY: all

all: heaps heaps2

heaps: heaps.c
	$(CC) $< -o $@

heaps2: heaps_recursive.c
	$(CC) $< -o $@

