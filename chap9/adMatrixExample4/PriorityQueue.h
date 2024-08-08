#include <stdlib.h>

typedef struct Node {
	int weight;
	int index;
	int from;
	int to;
} node;

typedef struct Heap {
	int size;
	int end;
	struct Node* array;	
} heap;

heap* createQueue(int size);
void enQueue(int weight, int start, int end, int index, heap* queue);
node deQueue(heap* queue);
void destroyQueue(heap* queue);
