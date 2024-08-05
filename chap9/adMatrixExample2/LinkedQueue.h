#include <stdlib.h>

typedef struct Node {
	int vertex;
	struct Node* nextNode;
} node;

typedef struct Queue {
	struct Node* front;
	struct Node* end;
} queue;

queue* createQueue();
void destroyQueue(queue* oldQueue);
int popQueue(queue* rootQueue);
void pushQueue(queue* rootQueue, int newVertex);
int queueIsEmpty(queue* rootQueue);
