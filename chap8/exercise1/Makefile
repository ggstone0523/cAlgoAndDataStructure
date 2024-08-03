all: build test clean

build:
	gcc -o AnswerTest AnswerTest.c Answer.c Answer.h

test:
	./AnswerTest

clean:
	rm -rf ./AnswerTest

debug:
	gcc -o AnswerTest AnswerTest.c Answer.c Answer.h
	gdb ./AnswerTest
	rm -rf ./AnswerTest

leak: build
	valgrind ./AnswerTest
	rm -rf ./AnswerTest

coverage:
	gcc --coverage -c AnswerTest.c
	gcc --coverage -c Answer.c
	gcc --coverage -o AnswerTest AnswerTest.o Answer.o Answer.h
	./AnswerTest
	gcov Answer.c
	lcov --directory ./ --capture --output-file app.info
	genhtml -o html_report app.info
	rm -rf *.gc* *.o AnswerTest app.info
