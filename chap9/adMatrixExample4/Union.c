#include "Union.h"

unionNode* createUnionNode(int index) {
	unionNode* newUnionNode = (unionNode*)malloc(sizeof(unionNode));

	newUnionNode->index = 0;
	newUnionNode->headUnion = NULL;

	return newUnionNode;
}

void destroyUnionNode(unionNode* oldUnionNode) {
	free(oldUnionNode);
}

void jointUnionNode(unionNode* parent, unionNode* child) {
	unionNode* temp = NULL;
	if(child->headUnion == NULL)
		child->headUnion = parent;
	else {
		temp = getHeadUnionNode(child);
		temp->headUnion = parent;
	}
}

unionNode* getHeadUnionNode(unionNode* currentUnionNode) {
	unionNode* temp = NULL;
	
	temp = currentUnionNode;
	while(temp->headUnion != NULL) {
		temp = temp->headUnion;
	}

	return temp;
}
