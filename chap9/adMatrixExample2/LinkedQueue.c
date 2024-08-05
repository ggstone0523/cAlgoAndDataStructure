#include "LinkedQueue.h"

queue* createQueue() {
	queue* newQueue = (queue*)malloc(sizeof(queue));

	newQueue->front = NULL;
	newQueue->end = NULL;

	return newQueue;
}

void destroyQueue(queue* oldQueue) {
	node* temp = NULL;
	node* current = NULL;

	current = oldQueue->front;

	while(current != NULL) {
		temp = current;
		current = current->nextNode;
		free(temp);
	}

	free(oldQueue);
}

int popQueue(queue* rootQueue) {
	node* temp = NULL;
	int vertex = 0;

	if(rootQueue->front == NULL)
		return 0;
	else {
		vertex = rootQueue->front->vertex;
		temp = rootQueue->front;
		rootQueue->front = rootQueue->front->nextNode;
		if(temp == rootQueue->end)
			rootQueue->end = NULL;
		free(temp);
		return vertex;
	}
}

void pushQueue(queue* rootQueue, int newVertex) {
	node* newNode = NULL;
	newNode = (node*)malloc(sizeof(node));
	newNode->vertex = newVertex;
	newNode->nextNode = NULL;

	if(rootQueue->front == NULL) {
		rootQueue->front = newNode;
		rootQueue->end = newNode;
	} else {
		rootQueue->end->nextNode = newNode;
		rootQueue->end = newNode;
	}
}

int queueIsEmpty(queue* rootQueue) {
	if(rootQueue->front == NULL)
		return 1;
	else
		return 0;
}
