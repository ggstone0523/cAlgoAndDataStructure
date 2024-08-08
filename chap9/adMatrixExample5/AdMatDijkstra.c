#include "AdMatDijkstra.h"
#include <stdio.h>

void Dijkstra(int** adMat, int start, int end, int** root, int startIndex) {
	heap* queue = NULL;
	node smallestNode;
	int* vertexVisit = NULL;
	int* weights = NULL;
	int* previousVertex = NULL;
	int index = 0;
	int i = 0;

	vertexVisit = (int*)malloc(sizeof(int) * end);
	weights = (int*)malloc(sizeof(int) * end);
	previousVertex = (int*)malloc(sizeof(int) * end);
	memset(vertexVisit, 0, sizeof(int) * end);
	memset(weights, -1, sizeof(int) * end);
	memset(previousVertex, 0, sizeof(int) * end);
	queue = createQueue(end);

	enQueue(0, startIndex, queue);
	weights[startIndex] = 0;
	while(queue->end > 0) {
		smallestNode = deQueue(queue);
		index = smallestNode.index;
		vertexVisit[index] = 1;
		
		for(i = start; i < end; i++) {
			if((adMat[index][i] > -1) && (vertexVisit[i] != 1) && (((adMat[index][i] + weights[index]) < weights[i]) || (weights[i] == -1))) {
				weights[i] = adMat[index][i] + weights[index];
				previousVertex[i] = index;
				enQueue(weights[i], i, queue);
			}
		}
	}

	for(i = start; i < end; i++) {
		root[previousVertex[i]][i] = weights[i];
	}

	destroyQueue(queue);
	free(vertexVisit);
	free(weights);
	free(previousVertex);
}
