#include "Answer.h"

int main() {
	char set = '\0';
	char *strArr[] = {"hello", "chocolate", "car", "movie", "drive", "rainbow", "hash"};
	char setArr[] = {'A', 'A', 'B', 'C', 'B', 'A', 'C'};
	int len = sizeof(strArr) / sizeof(strArr[0]);
	int i = 0;
	HT* hashtable = makeHashTable(11);
	
	printf("hashtable info: size=>%d, usage=>%d\n\n", hashtable->len, hashtable->usage);

	for(i = 0; i < len; i++) {
		setSET(strArr[i], setArr[i], hashtable);
	}
	for(i = 0; i < len; i++) {
		set = getSET(strArr[i], hashtable);
		printf("%s's set is %c\n", strArr[i], set);
	}

	printf("\nA union C\n\n");
	unionSET('A', 'C', hashtable);
	for(i = 0; i < len; i++) {
		set = getSET(strArr[i], hashtable);
		printf("%s's set is %c\n", strArr[i], set);
	}
	printf("\nhashtable info: size=>%d, usage=>%d\n", hashtable->len, hashtable->usage);
	
	printf("\ndelete hello key\n\n");
	deleteSETNode(strArr[0], hashtable);
	for(i = 0; i < len; i++) {
		set = getSET(strArr[i], hashtable);
		if(set != '\0')
			printf("%s's set is %c\n", strArr[i], set);
	}
	printf("\nhashtable info: size=>%d, usage=>%d\n", hashtable->len, hashtable->usage);
	
	printf("\ndelete union A\n\n");
	deleteSET('A', hashtable);
	for(i = 0; i < len; i++) {
		set = getSET(strArr[i], hashtable);
		if(set != '\0')
			printf("%s's set is %c\n", strArr[i], set);
	}
	printf("\nhashtable info: size=>%d, usage=>%d\n", hashtable->len, hashtable->usage);
	
	removeHashTable(hashtable);
	
	return 0;
}
