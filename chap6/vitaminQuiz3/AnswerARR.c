#include <stdio.h>
#include <string.h>

typedef struct block {
	int Number;
	int Count;
} Block;

int ARR_FrequencyCount(Block* arr, int target, int length);

int ARR_FrequencyCount(Block* arr, int target, int length) {
	int i = 0;
	int targetIndex = -1;
	Block temp;

	for(i = 0; i < length; i++) {
		if(arr[i].Number == target) {
			arr[i].Count++;
			targetIndex = i;
			break;
		}
	}
	if(targetIndex == -1)
		return -1;

	for(i = 0; i < length - 1; i++) {
		if(arr[i].Count <= arr[targetIndex].Count) {
			temp = arr[targetIndex];
			memmove(&arr[i+1], &arr[i], sizeof(arr[0]) * (targetIndex-i));
			arr[i] = temp;
			break;
		}
	}

	return targetIndex;
}

int main() {
	int i = 0;
	int j = 0;
	Block arr[10];
	int length = sizeof(arr) / sizeof(arr[0]);
	int targetarr[] = {5, 7, 8, 5, 8, 9, 0};
	int targetarrlen = sizeof(targetarr) / sizeof(targetarr[0]);

	for(i = 0; i < 10; i++) {
		arr[i].Number = i;
		arr[i].Count = 0;
	}

	for(i = 0; i < 9; i++) {
		printf("%d ", arr[i].Number);
	}
	printf("%d\n", arr[i].Number);
	
	for(j = 0; j < targetarrlen; j++) {
		ARR_FrequencyCount(arr, targetarr[j], length);
		for(i = 0; i < 9; i++) {
			printf("%d ", arr[i].Number);
		}
		printf("%d\n", arr[i].Number);
	}
	
	return 0;
}
