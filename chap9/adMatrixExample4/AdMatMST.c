#include "AdMatMST.h"
#include <stdio.h>

void Prim(int** adMat, int start, int end, int** root) {
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

	enQueue(0, 0, 0, start, queue);
	weights[start] = 0;
	while(queue->end > 0) {
		smallestNode = deQueue(queue);
		index = smallestNode.index;
		vertexVisit[index] = 1;
		
		for(i = start; i < end; i++) {
			if((adMat[index][i] > -1) && (vertexVisit[i] != 1) && ((adMat[index][i] < weights[i]) || (weights[i] == -1))) {
				weights[i] = adMat[index][i];
				previousVertex[i] = index;
				enQueue(adMat[index][i], 0, 0, i, queue);
			} else if((adMat[i][index] > -1) && (vertexVisit[i] != 1) && ((adMat[i][index] < weights[index]) || (weights[index] == -1))) {
				weights[index] = adMat[i][index];
				previousVertex[index] = i;
			} 
		}
	}

	for(i = start; i < end; i++) {
		root[previousVertex[i]][i] = weights[i];
		root[i][previousVertex[i]] = weights[i];
	}

	destroyQueue(queue);
	free(vertexVisit);
	free(weights);
	free(previousVertex);
}
 
void Kruskal(int** adMat, int start, int end, int** root) {
	unionNode** unionNodeArray;
	heap* queue = NULL;
	int i = 0, j = 0;
	int from = 0, to = 0;
	node smallestNode;
	unionNode* unionFromHeadNode;
	unionNode* unionToHeadNode;

	unionNodeArray = (unionNode**)malloc(sizeof(unionNode*) * (end - start));
	queue = createQueue(end);
	
	for(i = start; i < end; i++) {
		unionNodeArray[i - start] = createUnionNode(i);
	}

	for(i = start; i < end; i++) {
		for(j = start; j < end; j++) {
			if(adMat[i][j] >= 0) {
				enQueue(adMat[i][j], i, j, 0, queue);
			}
		}
	}

	while(queue->end > 0) {
		smallestNode = deQueue(queue);
		from = smallestNode.from;
		to = smallestNode.to;
		printf("%c - %c : %d\n", from, to, smallestNode.weight);

		unionFromHeadNode = getHeadUnionNode(unionNodeArray[from - start]);
		unionToHeadNode = getHeadUnionNode(unionNodeArray[to - start]);
		if(unionFromHeadNode != unionToHeadNode){
			jointUnionNode(unionNodeArray[from - start], unionNodeArray[to - start]);
			adMat[from - start][to - start] = smallestNode.weight;
			adMat[to - start][from - start] = smallestNode.weight;
		}
	}

	for(i = start; i < end; i++) {
		destroyUnionNode(unionNodeArray[i - start]);
	}

	free(unionNodeArray);
	destroyQueue(queue);
}
