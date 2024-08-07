#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void topologicalSort(int** adMat, node** root, int start, int end);
void TS_DFS(int** adMat, int vertex, int* vertexVisit, int size, node** root, int start);
