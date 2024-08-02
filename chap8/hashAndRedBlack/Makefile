all: build test clean

build:
	gcc -g -o AnswerTest Answer.c AnswerTest.c RedBlackTree.c RedBlackTree.h Answer.h

test:
	./AnswerTest

clean:
	rm -rf ./AnswerTest
