#ifndef ADMATGRAPH_H
#define ADMATGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** createGraph(int size);
void destroyGraph(int** adMat, int size);
void addEdge(int** adMat, int start, int end, int weight, int size);
void printGraph(int** adMat, int start, int end);

#endif
