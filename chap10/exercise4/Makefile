.SUFFIXES : .c .o
CC = gcc
CFLAGS = -g -Wall -ansi -std=c99
all: build clean

OBJS = BoyerMoore.o Test_BoyerMoore.o
SRCS = $(OBJS:.o=.c)

build: $(OBJS)
	$(CC) -o BoyerMoore $(OBJS)
	./BoyerMoore kjv.txt "Get wisdom"

clean: 
	rm -rf $(OBJS) BoyerMoore

leak: build
	valgrind ./BoyerMoore
	rm -rf $(OBJS) BoyerMoore

