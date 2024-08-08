#include "AdMatGraph.h"
#include "AdMatDijkstra.h"

int main() {
	int start = 'A';
	int end = 'I' + 1;
	int** root = createGraph(end);
	int** dijkstraRoot = createGraph(end);

	addEdge(root, 'A', 'B', 35, end);
	addEdge(root, 'A', 'E', 247, end);
	
	addEdge(root, 'B', 'A', 35, end);
	addEdge(root, 'B', 'C', 126, end);
	addEdge(root, 'B', 'F', 150, end);
	
	addEdge(root, 'C', 'B', 126, end);
	addEdge(root, 'C', 'D', 117, end);
	addEdge(root, 'C', 'F', 162, end);
	addEdge(root, 'C', 'G', 220, end);
	
	addEdge(root, 'D', 'C', 117, end);
	
	addEdge(root, 'E', 'A', 247, end);
	addEdge(root, 'E', 'F', 82, end);
	addEdge(root, 'E', 'H', 98, end);
	
	addEdge(root, 'F', 'B', 150, end);
	addEdge(root, 'F', 'C', 162, end);
	addEdge(root, 'F', 'E', 82, end);
	addEdge(root, 'F', 'G', 154, end);
	addEdge(root, 'F', 'H', 120, end);
	
	addEdge(root, 'G', 'C', 220, end);
	addEdge(root, 'G', 'F', 154, end);
	addEdge(root, 'G', 'I', 106, end);
	
	addEdge(root, 'H', 'E', 98, end);
	addEdge(root, 'H', 'F', 120, end);
	
	addEdge(root, 'I', 'G', 106, end);

	Dijkstra(root, start, end, dijkstraRoot, 'B');

	printGraph(dijkstraRoot, start, end);

	destroyGraph(root, end);
	destroyGraph(dijkstraRoot, end);
}
