#include "Answer.h"

int hash(char* key, int htLen) {
	int sum = 0;
	while(*key != '\0') {
		sum = (sum << 3) + *key;
		key++;
	}

	return sum % htLen;
}

int hash2(char* key, int htLen) {
	int sum = 0;
	while(*key != '\0') {
		sum = (sum << 2) + *key;
		key++;
	}

	return sum % (htLen - 2);
}

int findAddress(char *key, HT* ht, Node* array) {
	int address = hash(key, ht->len);
	int jump = hash2(key, ht->len);
	
	while(array[address].key != NULL && strcmp(array[address].key, key) != 0) {
		address = (address + jump) % ht->len;
	}
	
	return address;
}

void deleteSETNode(char* key, HT* ht) {
	int address = 0;

	address = findAddress(key, ht, ht->array);
	
	if(ht->array[address].key != NULL) {
		free(ht->array[address].key);
		ht->array[address].key = NULL;
		ht->array[address].set = '\0';
		ht->usage--;
		reduceHashTable(ht);
	}
}

char getSET(char *key, HT* ht) {
	int address = 0;
	
	address = findAddress(key, ht, ht->array);

	if(ht->array[address].key == NULL)
		return '\0';
	else
		return ht->array[address].set;
}

void setSET(char *key, char set, HT* ht) {
	int address = 0;
	int i = 0;
	int prevHtLen = ht->len;
	Node* newArray = NULL;
	
	address = findAddress(key, ht, ht->array);

	if(ht->array[address].key != NULL)
		free(ht->array[address].key);
		
	ht->array[address].key = (char*)malloc(strlen(key) + 1);
	strcpy(ht->array[address].key, key);
	ht->array[address].set = set;
	ht->usage++;

	if((ht->usage * 2) > (ht->len)) {
		ht->len *= 2;
		newArray = (Node*)malloc(sizeof(Node) * ht->len);
		memset(newArray, 0, sizeof(Node) * ht->len);
		for(i = 0; i < prevHtLen; i++) {
			if(ht->array[i].key != NULL) {
				address = findAddress(ht->array[i].key, ht, newArray);
				newArray[address] = ht->array[i];
			}
		}
		free(ht->array);
		ht->array = newArray;
	}
}

void unionSET(char upperSet, char lowerSet, HT* ht) {
	int i = 0;
	for(i = 0; i < ht->len; i++) {
		if(ht->array[i].key != NULL && ht->array[i].set == lowerSet) {
			ht->array[i].set = upperSet;
		}
	}
}

void deleteSET(char targetSet, HT* ht) {
	int i = 0;
	for(i = 0; i < ht->len; i++) {
		if(ht->array[i].key != NULL && ht->array[i].set == targetSet) {
			free(ht->array[i].key);
			ht->array[i].key = NULL;
			ht->array[i].set = '\0';
			ht->usage--;
		}
	}
	reduceHashTable(ht);
}

HT* makeHashTable(int htLen) {
	HT* ht = NULL;

	ht = (HT*)malloc(sizeof(HT));
	ht->array = (Node*)malloc(sizeof(Node) * htLen);
	memset(ht->array, 0, sizeof(Node) * ht->len);
	ht->len = htLen;
	ht->usage = 0;

	return ht;
}

void removeHashTable(HT* ht) {
	ht->len--;
	while(ht->len > -1 && ht->usage > 0) {
		if(ht->array[ht->len].key != NULL) {
			free(ht->array[ht->len].key);
			ht->usage--;
		}
		ht->len--;
	}

	free(ht->array);
	free(ht);
}

void reduceHashTable(HT* ht) {
	int i = 0;
	int address = 0;
	int prevHtLen = ht->len;
	Node* newArray = NULL;

	if((ht->len >= 2) && ((ht->usage * 4) < ht->len)) {
		ht->len = (int)(ht->len / 2);
		newArray = (Node*)malloc(sizeof(Node) * ht->len);
		memset(newArray, 0, sizeof(Node) * ht->len);
		for(i = 0; i < prevHtLen; i++) {
			if(ht->array[i].key != NULL) {
				address = findAddress(ht->array[i].key, ht, newArray);
				newArray[address] = ht->array[i];
			}
		}
		free(ht->array);
		ht->array = newArray;
	}
}
