#include "ArrayStack.h"

void AS_Push(ArrayStack* Stack, ElementType Data)
{
	int Position = Stack->Top;
	int Capacity = Stack->Capacity;
	int index = 0;
	Node* NewNodes;

	if(Position == Capacity) {
		Stack->Capacity = Capacity + (int)(Capacity * 0.3);
		NewNodes = (Node*)malloc(sizeof(Node) * Stack->Capacity);
		for(index = 0; index <= Position; index++) {
			NewNodes[index].Data = Stack->Nodes[index].Data;
		}
		free(Stack->Nodes);
		Stack->Nodes = NewNodes;
	}

	Stack->Nodes[Stack->Top].Data = Data;
	Stack->Top++;
}
