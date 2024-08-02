#include "Answer.h"

RBTNode* Nil;

int main() {
	char *data = NULL;
	char *keyArr[] = {"hello", "chocolate", "car", "movie", "drive", "rainbow", "hash"};
	char *dataArr[] = {"AA", "BB", "CC", "DD", "EE", "FF", "GG"};
	int len = sizeof(keyArr) / sizeof(keyArr[0]);
	int i = 0;

	Nil = RBT_CreateNode("\0", "\0");
        Nil->Color = BLACK;

	HT* hashtable = makeHashTable(11);
	
	printf("hashtable info: size=>%d\n\n", hashtable->len);

	for(i = 0; i < len; i++) {
		setSET(keyArr[i], dataArr[i], hashtable);
	}
	
	for(i = 0; i < len; i++) {
		data = getSET(keyArr[i], hashtable);
		printf("%s's data is %s\n", keyArr[i], data);
	}

	return 0;
}
