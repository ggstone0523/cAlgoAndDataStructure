#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int Data;
	int Count;
	struct node* NextNode;
} Node;

void SLL_Frequency(Node** root, int target);
Node* createNode(int data);
void deleteNode(Node* oldNode);
void addNode(Node** root, Node* newNode);
Node* removeNode(Node** root, int data);

Node* createNode(int data) {
	Node* newNode = NULL;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = data;
	newNode->Count = 0;
	newNode->NextNode = NULL;

	return newNode;
}

void deleteNode(Node* oldNode) {
	free(oldNode);
}

void addNode(Node** root, Node* newNode) {
	Node* temp = *root;
	
	if(*root == NULL) {
		*root = newNode;
	} else {
		while(temp->NextNode != NULL)
			temp = temp->NextNode;
		temp->NextNode = newNode;
	}
}

Node* removeNode(Node** root, int data) {
	Node* before = NULL;
	Node* temp = *root;
	
	if(temp->Data == data) {
		*root = temp->NextNode;
	} else {
		while(temp != NULL) {
			if(temp->Data == data)
				break;
			before = temp;
			temp = temp->NextNode;
		}
		if(temp != NULL) {
			before->NextNode = temp->NextNode;
			deleteNode(temp);
		}
	}
}

void SLL_Frequency(Node** root, int target) {
	Node* current = *root;
	Node* beforeC = *root;
	Node* beforeA = *root;
	Node* answer = NULL;

	while(current != NULL) {
		if(current->Data == target) {
			current->Count++;
			break;
		}
		beforeA = current;
		current = current->NextNode;
	}
	if(current == NULL)
		return;
	answer = current;

	current = *root;
	while(current != NULL) {
		if(current->Count <= answer->Count) {
			break;
		}
		beforeC = current;
		current = current->NextNode;
	}
	if(current == *root) {
		beforeA->NextNode = answer->NextNode;
		answer->NextNode = current;
		*root = answer;
	} else if(current != NULL) {
		beforeA->NextNode = answer->NextNode;
		answer->NextNode = current;
		beforeC->NextNode = answer;
	}
}

int main() {
	Node* newNode;
	Node* root;
	Node* temp;
	int i = 0;
	int j = 0;
	int targetarr[] = {5, 7, 8, 5, 8, 9, 0};
	int targetarrlen = sizeof(targetarr) / sizeof(targetarr[0]);

	for(i = 0; i < 10; i++) {
		newNode = createNode(i);
		addNode(&root, newNode);
	}
	
	temp = root;
	while(temp->NextNode != NULL) {
		printf("%d ", temp->Data);
		temp = temp->NextNode;
	}
	printf("%d\n", temp->Data);
	
	for(j = 0; j < targetarrlen; j++) {
		SLL_Frequency(&root, targetarr[j]);
		temp = root;
		while(temp->NextNode != NULL) {
			printf("%d ", temp->Data);
			temp = temp->NextNode;
		}
		printf("%d\n", temp->Data);
	}

	return 0;
}
