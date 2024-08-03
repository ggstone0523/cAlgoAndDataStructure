#include "LinkedList.h"

int main() {
	int length = 6;
	Node* adList[length];
	Node* newNode;
	memset(adList, 0, sizeof(Node*) * length);

	newNode = createNewNode(2);
	addNewNode(1, newNode, adList);
	newNode = createNewNode(3);
	addNewNode(1, newNode, adList);
	newNode = createNewNode(4);
	addNewNode(1, newNode, adList);
	newNode = createNewNode(5);
	addNewNode(1, newNode, adList);

	newNode = createNewNode(3);
	addNewNode(2, newNode, adList);
	newNode = createNewNode(5);
	addNewNode(2, newNode, adList);
	
	newNode = createNewNode(5);
	addNewNode(4, newNode, adList);
	
	printAdList(adList, length);
	
	freeAdList(adList, length);

	return 0;
}
