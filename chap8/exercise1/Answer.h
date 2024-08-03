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
void deleteSETNode(char* key, HT* ht);
char getSET(char *key, HT* ht);
void setSET(char *key, char set, HT* ht);
void unionSET(char upperSet, char lowerSet, HT* ht);
void deleteSET(char targetSet, HT* ht);
HT* makeHashTable(int htlen);
void removeHashTable(HT* ht);
void reduceHashTable(HT* ht);
