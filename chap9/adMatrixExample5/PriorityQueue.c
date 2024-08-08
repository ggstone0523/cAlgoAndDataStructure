#include "PriorityQueue.h"
#include <stdio.h>

heap* createQueue(int size) {
	heap* newQueue = NULL;

	newQueue = (heap*)malloc(sizeof(heap));
	newQueue->size = size;
	newQueue->end  = 0;
	newQueue->array = (node*)malloc(sizeof(node) * size);

	return newQueue;
}

void enQueue(int weight, int index, heap* queue) {
	node tempNode;
	int from = 0;
	int to = 0;

	queue->array[queue->end].weight = weight;
	queue->array[queue->end].index = index;
	from = queue->end;
	to = (queue->end - 1) / 2;

	while((to > 0) && (queue->array[to].weight > queue->array[from].weight)) {
		tempNode = queue->array[from];
		queue->array[from] = queue->array[to];
		queue->array[to] = tempNode;
		from = to;
		to = (to - 1) / 2;
	}
	if(to == 0 && (queue->array[to].weight > queue->array[from].weight)) {
		tempNode = queue->array[from];
		queue->array[from] = queue->array[to];
		queue->array[to] = tempNode;
	}
	
	queue->end++;

	if(queue->end == queue->size) {
		queue->size *= 2;
		queue->array = (node*)realloc(queue->array, sizeof(node) * queue->size);
	}
}

node deQueue(heap* queue) {
	node tempNode;
	int from = 0;
	int to = 0;

	tempNode = queue->array[0];
	queue->end--;
	queue->array[0] = queue->array[queue->end];
	queue->array[queue->end] = tempNode;

	while(to < queue->end) {
		if(queue->array[(from * 2) + 1].weight < queue->array[(from * 2) + 2].weight)
			to = (from * 2) + 1;
		else
			to = (from * 2) + 2;
		if((to < queue->end) && (queue->array[from].weight > queue->array[to].weight)) {
			tempNode = queue->array[from];
			queue->array[from] = queue->array[to];
			queue->array[to] = tempNode;
		} else
			break;

		from = to;
	}

	return queue->array[queue->end];
}

void destroyQueue(heap* queue) {
	free(queue->array);
	free(queue);
}
