#include <stdio.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
	struct tagNode* NextNode;	
} Node;

int main() {
	printf("sizeof(Node) : %ld\n", sizeof(Node)); // 구조체의 크기를 가리킴.
	printf("sizeof(Node*): %ld\n", sizeof(Node*)); // 구조체를 가리키는 포인터의 크기를 가리킴.
	return 0;
}
