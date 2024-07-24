#include "ArrayStack.h"

ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top;
	int Capacity = Stack->Capacity;
	int index = 0;
	Node* NewNodes;
	
	if(Position == (Capacity - (int)(Capacity * 0.3))) {
		Stack->Capacity = Position;
		NewNodes = (Node*)malloc(sizeof(Node) * Stack->Capacity);
		for(index = 0; index < Position; index++) {
			NewNodes[index].Data = Stack->Nodes[index].Data;
		}
		free(Stack->Nodes);
		Stack->Nodes = NewNodes;
	}

	Position = --( Stack->Top );
	return Stack->Nodes[Position].Data;
}
