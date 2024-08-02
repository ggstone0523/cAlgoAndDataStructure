all: build test clean

build:
	gcc -g -o AnswerTest AnswerTest.c Answer.c Answer.h

test:
	./AnswerTest

clean:
	rm -rf ./AnswerTest

debug: build
	gdb ./AnswerTest
	rm -rf ./AnswerTest
