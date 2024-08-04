#include "AdMatGraph.h"

int main() {
	int** adMat = NULL;
	int graphSize = 6;

	adMat = createGraph(graphSize);

	addEdge(adMat, 1, 2, 0, graphSize);
	addEdge(adMat, 1, 3, 0, graphSize);
	addEdge(adMat, 1, 4, 0, graphSize);
	addEdge(adMat, 1, 5, 0, graphSize);
	
	addEdge(adMat, 2, 1, 0, graphSize);
	addEdge(adMat, 2, 3, 0, graphSize);
	addEdge(adMat, 2, 5, 0, graphSize);
	
	addEdge(adMat, 3, 1, 0, graphSize);
	addEdge(adMat, 3, 2, 0, graphSize);
	
	addEdge(adMat, 4, 1, 0, graphSize);
	addEdge(adMat, 4, 5, 0, graphSize);
	
	addEdge(adMat, 5, 1, 0, graphSize);
	addEdge(adMat, 5, 2, 0, graphSize);
	addEdge(adMat, 5, 4, 0, graphSize);

	printGraph(adMat, graphSize);

	destroyGraph(adMat, graphSize);

	return 0;
}
