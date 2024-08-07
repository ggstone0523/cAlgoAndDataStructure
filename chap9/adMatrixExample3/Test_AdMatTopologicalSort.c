#include "AdMatGraph.h"
#include "AdMatTopologicalSort.h"

int main() {
	int** adMat = NULL;
	int start = 'A';
	int end = 'H';
	int size  = end + 1;
	node* root = NULL;
	node* temp = NULL;

	adMat = createGraph(size);
	
	addEdge(adMat, 'A', 'C', 0, size);
	addEdge(adMat, 'A', 'D', 0, size);
	
	addEdge(adMat, 'B', 'C', 0, size);
	addEdge(adMat, 'B', 'E', 0, size);
	
	addEdge(adMat, 'C', 'F', 0, size);
	
	addEdge(adMat, 'D', 'F', 0, size);
	addEdge(adMat, 'D', 'G', 0, size);
	
	addEdge(adMat, 'E', 'G', 0, size);
	
	addEdge(adMat, 'F', 'H', 0, size);
	
	addEdge(adMat, 'G', 'H', 0, size);

	topologicalSort(adMat, &root, start, end);

	printf("Topological Sort Result :");

	temp = root;
	while(temp != NULL) {
		printf(" %c", temp->vertex);
		temp = temp->nextNode;
	}
	printf("\n");

	deleteLinkedList(&root);
	destroyGraph(adMat, size);

	return 0;
}
