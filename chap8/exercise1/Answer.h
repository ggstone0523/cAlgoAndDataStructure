#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char* key;
	char set;
} Node;

typedef struct ht {
	Node* array;
	int len;
	int usage;
} HT;

int hash(char* key, int htLen);
int hash2(char* key, int htLen);
int findAddress(char *key, HT* ht, Node* array);
char getSET(char *key, HT* ht);
void setSET(char *key, char set, HT* ht);
void unionSET(char upperSet, char lowerSet, HT* ht);
HT* makeHashTable(int htlen);
void removeHashTable(HT* ht);
