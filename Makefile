#
# Generic compiles-it-all Makefile
#  Loni Nix <lornix@lornix.com>
#    Last modified 2011-08-17
#
# adhere to a higher standard!
#CFLAGS+=-std=c99
#CFLAGS+=-std=c11
# pretty much always want debugging symbols included
CFLAGS+=-ggdb3
# yell out all warnings and whatnot
CFLAGS+=-Wall -Wextra -Wunused
# make all warnings into errors
CFLAGS+=-Werror
# link time optimization! cool! smaller exec's!
#CFLAGS+=-flto
#LDFLAGS+=-flto
# optimize!
#CFLAGS+=-O3
# or not!
CFLAGS+=-O0
# enable for gmon performance statistics
#CFLAGS+=-pg
# preserve everything used to create binary, verbose assembly comments
#CFLAGS+=-masm=intel --save-temps -fverbose-asm
# if we're playing with threaded code
#CFLAGS+=-pthread
# generate report showing time spent in each phase of compilation
#CFLAGS+=-ftime-report
# general call log
#CFLAGS+=-fdump-tree-cfg-lineno
#
# C++ stuff mostly the same as C flags
CXXFLAGS=$(CFLAGS)
#
# das linker flags
# LDFLAGS+=
LDFLAGS+=-lm
# LDFLAGS+=-lbfd
# LDFLAGS+=-Wl,--as-needed
# LDFLAGS+=-lbluetooth
# LDFLAGS+=-lncursesw
# LDFLAGS+=-lcurl
# LDFLAGS+=-lX11
# LDFLAGS+=-lmagic
LDFLAGS+=-lSDL2
LDFLAGS+=-lcairo
#
# NASM flags
NFLAGS+=-g
#NFLAGS+=-O0
NFLAGS+=-felf64
#
CC:=gcc
CXX:=g++
NASM:=nasm
#
.SUFFIXES:
.SUFFIXES: .c .cpp .asm .o
#
SHELL=/bin/sh
#
CSRC:=$(wildcard *.c)
CPRG:=$(basename $(CSRC))
COBJ:=$(addsuffix .o,$(CPRG))
#
CXXSRC:=$(wildcard *.cpp)
CXXPRG:=$(basename $(CXXSRC))
CXXOBJ:=$(addsuffix .o,$(CXXPRG))
#
ASMSRC:=$(wildcard *.asm)
ASMPRG:=$(basename $(ASMSRC))
ASMOBJ:=$(addsuffix .o,$(ASMPRG))
#
.PHONY: all clean

all: $(CPRG) $(CXXPRG) $(ASMPRG)

% : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

% : %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

% : %.asm
	$(NASM) $(NFLAGS) -o $@.o $< # -l $@.lst
	$(LD) -o $@ $@.o -lc || $(CC) -o $@ $@.o -lc

ignored:
	#$(LD) $(LDFLAGS) -q -o $@ $@.o || $(CC) -o $@ $@.o
	#rm $@.o

clean:
	-rm $(CPRG) $(CXXPRG) $(ASMPRG)

