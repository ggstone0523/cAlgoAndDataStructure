#include "AdMatGraph.h"

int** createGraph(int size) {
	int i = 0;
	int** adMat;

	adMat = (int**)malloc(sizeof(int*) * size);
	for(i = 0; i < size; i++) {
		adMat[i] = (int*)malloc(sizeof(int) * size);
		memset(adMat[i], -1, sizeof(int) * size);
	}

	return adMat;
}

void destroyGraph(int** adMat, int size) {
	int i = 0;
	for(i = 0; i < size; i++) {
		free(adMat[i]);
	}
	free(adMat);
}

void addEdge(int** adMat, int start, int end, int weight, int size) {
	if(start >= size || start < 0) {
		printf("Edge start location error!\n");
		return;
	}
	
	if(end >= size || end < 0) {
		printf("Edge end location error!\n");
		return;
	}

	adMat[start][end] = weight;
}

void printGraph(int** adMat, int size) {
	int i = 0;
	int j = 0;
	
	for(i = 1; i < size; i++) {
		printf("%d :", i);
		for(j = 1; j < size; j++)
			if(adMat[i][j] > -1)
				printf(" %d[%d]", j, adMat[i][j]);
		printf("\n");
	}
}
