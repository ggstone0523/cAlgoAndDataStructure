#include "RedBlackTree.h"

typedef struct ht {
	RBTNode** array;
	int len;
} HT;

int hash(char* key, int htLen);
char* getSET(char *key, HT* ht);
void setSET(char *key, char *value, HT* ht);
HT* makeHashTable(int htlen);
void removeHashTable(HT* ht);
