#include "AdMatGraph.h"
#include "AdMatGraphTraversal.h"

int main() {
	int** adMat = NULL;
	int graphSize = 8;
	int mode = 0;

	adMat = createGraph(graphSize);

	addEdge(adMat, 1, 2, 0, graphSize);
	addEdge(adMat, 1, 3, 0, graphSize);
	
	addEdge(adMat, 2, 4, 0, graphSize);
	addEdge(adMat, 2, 5, 0, graphSize);
	
	addEdge(adMat, 3, 4, 0, graphSize);
	addEdge(adMat, 3, 6, 0, graphSize);
	
	addEdge(adMat, 4, 5, 0, graphSize);
	addEdge(adMat, 4, 7, 0, graphSize);
	
	addEdge(adMat, 5, 7, 0, graphSize);
	
	addEdge(adMat, 6, 7, 0, graphSize);

	printf("Enter Tarversal Mode (0:DFS, 1:BFS) : ");
	scanf("%d", &mode);

	if(mode == 0) {
		DFS(adMat, graphSize);
	} else {
		BFS(adMat, graphSize);
	}

	destroyGraph(adMat, graphSize);

	return 0;
}
