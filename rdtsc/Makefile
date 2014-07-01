#
.phony: all

all: rdtsc

rdtsc: rdtsc.s
	as -ggdb3 rdtsc.s -o rdtsc.o
	ld rdtsc.o -o rdtsc
	rm rdtsc.o

clean:
	rm -f rdtsc.o rdtsc

