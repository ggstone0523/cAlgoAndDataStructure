#include "AdMatTopologicalSort.h"

void topologicalSort(int** adMat, node** root, int start, int end) {
	int i = 0;
	int j = 0;
	int* vertexVisit = NULL;
	int* vertexNotInput = NULL;
	int size = end + 1;

	vertexVisit = (int*)malloc(sizeof(int) * size);
	memset(vertexVisit, 0, sizeof(int) * size);
	vertexNotInput = (int*)malloc(sizeof(int) * size);
	memset(vertexNotInput, 0, sizeof(int) * size);

	for(i = start; i < size; i++) {
		for(j = start; j < size; j++) {
			if(adMat[j][i] >= 0)
				break;
		}
		if(j == size) {
			vertexNotInput[i] = 1;
		}
	}

	for(i = start; i < size; i++) {
		if(vertexVisit[i] == 0 && vertexNotInput[i] == 1)
			TS_DFS(adMat, i, vertexVisit, size, root, start);
	}

	free(vertexVisit);
	free(vertexNotInput);
}

void TS_DFS(int** adMat, int vertex, int* vertexVisit, int size, node** root, int start) {
	int target = 0;
	int i = 0;
	node* newNode = NULL;

	vertexVisit[vertex] = 1;

	for(i = start; i < size; i++) {
		if(adMat[vertex][i] >= 0 && vertexVisit[i] == 0)
			TS_DFS(adMat, i, vertexVisit, size, root, start);
	}

	printf("%c\n", vertex);

	newNode = createNode(vertex);
	addNodeToRoot(root, newNode);
} 
