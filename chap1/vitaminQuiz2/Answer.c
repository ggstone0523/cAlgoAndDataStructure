#include "LinkedList.h"

void SLL_DestoryAllNodes(Node** List) {
	int Count = 0;
	int i = 0;
	Node* Current = NULL;

	Count = SLL_GetNodeCount((*List));
	for(i = 0; i < Count; i++) {
		Current = SLL_GetNodeAt((*List), 0);
		if(Current != NULL) {
			SLL_RemoveNode(List, Current);
			SLL_DestoryNode(Current);
		}
	}
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead) {
	Node* Temp = NULL;
	
	if((*Head) == NULL) {
		(*Head) = NewHead;
	} else if((*Head) == Current) {
		NewHead->NextNode = Current;
		(*Head) = NewHead;
	} else {
		Temp = *Head;
		while(Temp != NULL && Temp->NextNode != Current) {
			Temp = Temp->NextNode;
		}
		if(Temp != NULL) {
			NewHead->NextNode = Temp->NextNode;
			Temp->NextNode = NewHead;
		}
	}
}
