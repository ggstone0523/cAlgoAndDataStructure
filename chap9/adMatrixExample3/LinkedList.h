#include <stdlib.h>

typedef struct Node {
	int vertex;
	struct Node* nextNode;
} node;

node* createNode(int vertex);
void addNodeToRoot(node** root, node* newNode);
void deleteLinkedList(node** root);
