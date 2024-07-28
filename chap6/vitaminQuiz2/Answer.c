#include <stdio.h>
#include <string.h>

int ALL_Transpose(int* array, int target, int length);
int stoi(char *snum);

int ALL_Transpose(int* array, int target, int length) {
	int i = 0;

	for(i = 0; i < length; i++) {
		if(array[i] == target && i != 0) {
			array[i] = array[i-1];
			array[i-1] = target;
			break;	
		}
	}
	return i - 1;
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
	int target1 = 0;
	int target2 = 0;
	int target3 = 0;
	int length = 0;	
	int i = 1;
	int targetIndex = 0;
	
	if(argc < 2) {
		printf("Usage: ./Answer ArrLen Arr Target1 Target2 Target3\n");
		return 0;
	}

	length = stoi(argv[i]);
	for(i++; i <= (1 + length); i++) {
		arr[i-2] = stoi(argv[i]);
	}
	target1 = stoi(argv[i]);
	i++;
	target2 = stoi(argv[i]);
	i++;
	target3 = stoi(argv[i]);

	targetIndex = ALL_Transpose(arr, target1, length);
	printf("targetIndex: %d, target: %d\n", targetIndex, arr[targetIndex]);
	for(i = 0; i < length - 1; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[i]);
	
	targetIndex = ALL_Transpose(arr, target2, length);
	printf("targetIndex: %d, target: %d\n", targetIndex, arr[targetIndex]);
	for(i = 0; i < length - 1; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[i]);
	
	targetIndex = ALL_Transpose(arr, target3, length);
	printf("targetIndex: %d, target: %d\n", targetIndex, arr[targetIndex]);
	for(i = 0; i < length - 1; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[i]);

	return 0;
}
