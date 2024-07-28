all: build test clean

build:
	gcc -o AnswerSLL AnswerSLL.c
	gcc -o AnswerARR AnswerARR.c

test:
	./AnswerSLL
	./AnswerARR

clean:
	rm -rf ./AnswerSLL ./AnswerARR
