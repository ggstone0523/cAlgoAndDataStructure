#include <stdio.h>
#include <string.h>

int ALL_MoveToFront(int* array, int target, int length);
int stoi(char *snum);

int ALL_MoveToFront(int* array, int target, int length) {
	int i = 0;
	int temp = 0;

	for(i = 0; i < length; i++) {
		if(array[i] == target && i != 0) {
			temp = target;
			memmove(&array[1], &array[0], sizeof(array[0]) * i);
			array[0] = target;
			break;	
		}
	}

	return 0;
}

int stoi(char *snum) {
	int num = 0;

	while(*snum != '\0') {
		num = num * 10 + (*snum - '0');
		snum++;
	}

	return num;
}

int main(int argc, char **argv) {
	int arr[1024];
	int target = 0;
	int length = 0;	
	int i = 1;
	int targetIndex = 0;
	
	if(argc < 2) {
		printf("Usage: ./Answer ArrLen Arr Target\n");
		return 0;
	}

	length = stoi(argv[i]);
	for(i++; i <= (1 + length); i++) {
		arr[i-2] = stoi(argv[i]);
	}
	target = stoi(argv[i]);

	targetIndex = ALL_MoveToFront(arr, target, length);

	printf("targetIndex: %d, target: %d\n", targetIndex, arr[targetIndex]);
	for(i = 0; i < length - 1; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[i]);

	return 0;
}
