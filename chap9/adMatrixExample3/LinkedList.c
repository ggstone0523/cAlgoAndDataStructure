#include "LinkedList.h"

node* createNode(int vertex) {
	node* newNode = NULL;

	newNode = (node*)malloc(sizeof(node));
	newNode->vertex = vertex;
	newNode->nextNode = NULL;

	return newNode;
}

void addNodeToRoot(node** root, node* newNode) {
	if(*root == NULL) {
		*root = newNode;
	} else {
		newNode->nextNode = *root;
		*root = newNode;
	}
}

void deleteLinkedList(node** root) {
	node* temp = NULL;
	node* current = NULL;

	temp = *root;
	current = *root;
	while(current != NULL) {
		temp = current;
		current = current->nextNode;
		free(temp);
	}
}
