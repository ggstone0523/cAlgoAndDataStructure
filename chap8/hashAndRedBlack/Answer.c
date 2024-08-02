#include "Answer.h"

int hash(char* key, int htLen) {
	int sum = 0;
	while(*key != '\0') {
		sum = (sum << 3) + *key;
		key++;
	}

	return sum % htLen;
}

char* getSET(char *key, HT* ht) {
	int address = 0;
	RBTNode* Node = NULL;

	address = hash(key, ht->len);

	Node = RBT_SearchNode(ht->array[address], key);
	if(Node == NULL)
		return '\0';
	else
		return Node->Data;
}

void setSET(char *key, char* value, HT* ht) {
	int address = 0;
	int i = 0;
	int prevHtLen = ht->len;
	
	address = hash(key, ht->len);
	RBT_InsertNode(&(ht->array[address]), RBT_CreateNode(key, value));
}

HT* makeHashTable(int htLen) {
	HT* ht = NULL;

	ht = (HT*)malloc(sizeof(HT));
	ht->array = (RBTNode**)malloc(sizeof(RBTNode*) * htLen);
	ht->len = htLen;

	return ht;
}

void removeHashTable(HT* ht) {
	ht->len--;
	while(ht->len > -1) {
		if(ht->array[ht->len] != NULL) {
			RBT_DestroyTree(ht->array[ht->len]);
		}
		ht->len--;
	}

	free(ht->array);
	free(ht);
}
