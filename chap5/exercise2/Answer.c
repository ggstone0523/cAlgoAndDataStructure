#include "DoublyLinkedList.h"

void InsertionSort(Node** Root) {
	Node* Current = *Root;
	Node* Start = *Root;
	Node* Find = *Root;
	
	while(Current->NextNode != NULL) {
		if(Current->Data <= Current->NextNode->Data) {
			Current = Current->NextNode;
			continue;
		}
		
		Start = *Root;
		Find = Current->NextNode;
		while(Start->Data < Find->Data) {
			Start = Start->NextNode;
		}
		Current->NextNode = Find->NextNode;
		if(Find->NextNode != NULL)
			Find->NextNode->PrevNode = Current;
		if(Start->PrevNode != NULL)
			Start->PrevNode->NextNode = Find;
		else
			*Root = Find;
		Find->PrevNode = Start->PrevNode;
		Start->PrevNode = Find;
		Find->NextNode = Start;
	}
}
