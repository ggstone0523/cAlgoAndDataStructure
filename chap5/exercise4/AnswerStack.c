#include "AnswerStack.h"

int Stack[1024];
int StackIndex = 0;

void Push(int num) {
	Stack[StackIndex] = num;
	StackIndex++;
}

int Pop() {
	StackIndex--;
	return Stack[StackIndex];
}

int StackIsEmpty() {
	if(StackIndex == 0)
		return 1;
	else
		return 0;
}
