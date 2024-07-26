#include "LCRSTree.h"

void LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level) {
	void __LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level); 
	
	printf("level%d: ", Level);
	__LCRS_PrintNodesAtLevel(Root, Level);
	printf("\n");
}

void __LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level) {
	if(Level == 0) {
		printf("%c ", Root->Data);
	}
	if(Level < 0)
		return;

	if(Root->LeftChild != NULL)
		__LCRS_PrintNodesAtLevel(Root->LeftChild, Level-1);
	
	if(Root->RightSibling != NULL)
		__LCRS_PrintNodesAtLevel(Root->RightSibling, Level);
}
