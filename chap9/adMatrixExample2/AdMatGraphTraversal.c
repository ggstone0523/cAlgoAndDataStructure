#include "AdMatGraphTraversal.h"

void DFS(int** adMat, int size) {
	int i = 1;
	int previ = -1;
	int j = 1;
	int* vertexVisit = NULL;
	int* stack = NULL;
	int top = 0;

	stack = (int*)malloc(sizeof(int) * size);
	stack[top] = i;
	top++;

	vertexVisit = (int*)malloc(sizeof(int) * size);
	memset(vertexVisit, 0, sizeof(int) * size);
	vertexVisit[i] == 1;
	
	printf("%d", i);
	while(top > 0) {
		if(j == size) {
			top--;
			i = stack[top];
		}
		if(previ == i)
			continue;
		for(j = 1; j < size; j++) {
			if(adMat[i][j] >= 0 && vertexVisit[j] == 0) {
				printf(" %d", j);
				vertexVisit[j] = 1;
				stack[top] = j;
				top++;
				break;
			}
		}
		previ = i;
		i = j;
	}
	printf("\n");

	free(vertexVisit);
	free(stack);
}

void BFS(int** adMat, int size) {
	int i = 1;
	int j = 1;
	int* vertexVisit = NULL;
	queue* rootQueue = NULL;

	rootQueue = createQueue();
	pushQueue(rootQueue, i);

	vertexVisit = (int*)malloc(sizeof(int) * size);
	memset(vertexVisit, 0, sizeof(int) * size);
	vertexVisit[i] == 1;

	printf("%d", i);
	while(!queueIsEmpty(rootQueue)) {
		i = popQueue(rootQueue);
		for(j = 1; j < size; j++) {
			if(adMat[i][j] >= 0 && vertexVisit[j] == 0) {
				printf(" %d", j);
				vertexVisit[j] = 1;
				pushQueue(rootQueue, j);
			}
		}	
	}
	printf("\n");

	free(vertexVisit);
	destroyQueue(rootQueue);
}
