#include "LinkedList.h"

Node* createNewNode(int data) {
	Node* newNode = NULL;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->nextNode = NULL;

	return newNode;
}

void addNewNode(int vertex, Node* newNode, Node* adList[]) {
	Node* temp = NULL;
	
	if(adList[vertex] == NULL)
		adList[vertex] = newNode;
	else {
		temp = adList[vertex];
		while(temp->nextNode != NULL)
			temp = temp->nextNode;
		temp->nextNode = newNode;
	}
}

void freeAdList(Node* adList[], int length) {
	int i = 0;
	Node* temp = NULL;
	Node* prev = NULL;

	for(i = 0; i < length; i++) {
		temp = adList[i];
		while(temp != NULL) {
			prev = temp;
			temp = temp->nextNode;
			free(prev);
		}
	}
}

void printAdList(Node* adList[], int length) {
	int i = 0;
	Node* temp = NULL;

	for(i = 1; i < length; i++) {
		temp = adList[i];
		printf("%d =>", i);
		if(temp == NULL) {
			printf(" NONE\n");
			continue;
		}
		while(temp->nextNode != NULL) {
			printf(" %d,", temp->data);
			temp = temp->nextNode;
		}
		printf(" %d\n", temp->data);
	}
}
