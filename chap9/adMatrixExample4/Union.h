#include <stdlib.h>

typedef struct UnionNode {
	int index;
	struct UnionNode* headUnion;
} unionNode;

unionNode* createUnionNode(int index);
void destroyUnionNode(unionNode* oldUnionNode);
void jointUnionNode(unionNode* parent, unionNode* child);
unionNode* getHeadUnionNode(unionNode* currentUnionNode);
