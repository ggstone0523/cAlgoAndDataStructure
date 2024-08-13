#include <stdio.h>
#include <stdlib.h>

int Factorial(int N) {
	int* Stack = NULL;
	int Top = 0;
	int Answer = 0;

	if(N == 0) {
		return 1;
	}
	
	Stack = (int*)malloc(sizeof(int) * N);
	
	while(N > 0) {
		Stack[Top] = N;
		Top++;
		N--;
	}

	Top--;
	Answer = Stack[Top];
	while(Top > 0) {
		Top--;	
		Answer = Answer * Stack[Top];
	}

	free(Stack);

	return Answer;
}

int Stoi(char* N) {
	int Answer = 0;
	int Index = 0;

	while((N[Index] <= '9') && (N[Index] >= '0')) {
		Answer = Answer * 10 + (N[Index] - '0');
		Index++;
	}

	return Answer;
}

int main(int argc, char** argv) {
	int N = 0;
	
	if(argc != 2) {
		printf("Usage: ./Factorial N\n");
		return 0;
	}

	N = Stoi(argv[1]);

	printf("%d! == %d\n", N, Factorial(N));

	return 0;
}
