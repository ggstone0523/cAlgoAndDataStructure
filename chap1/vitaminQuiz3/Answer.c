#include "DoublyLinkedList.h"

void PrintReverse(Node* Head) {
	int Count = 0;
	int i = 0;
	Node* Temp = NULL;

	Count = DLL_GetNodeCount(Head);
	Temp = DLL_GetNodeAt(Head, Count - 1);
	for(i = Count - 1; i >= 0; i--) {
		printf("List[%d] : %d\n", i, Temp->Data);
		Temp = Temp->PrevNode;
	}
}
