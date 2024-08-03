#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* nextNode;
} Node;

Node* createNewNode(int data);
void addNewNode(int vertex, Node* newNode, Node* adList[]);
void freeAdList(Node* adList[], int length);
void printAdList(Node* adList[], int length);
