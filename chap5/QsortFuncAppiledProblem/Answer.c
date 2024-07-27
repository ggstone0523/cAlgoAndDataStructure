#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

int ComparePoint(const void *_pt1, const void *_pt2) {
	Point* pt1 = (Point*)_pt1;
	Point* pt2 = (Point*)_pt2;

	if(pt1->point > pt2->point)
		return 1;
	else if(pt1->point < pt2->point)
		return -1;
	else
		return 0;
}

int main() {
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int ComparePoint(const void *_pt1, const void *_pt2);
	int i = 0;

	qsort((void*)DataSet, Length, sizeof(Point), ComparePoint);

	printf("14,142st Client    ID: %5d\n", DataSet[14142 - 1].id);
	printf("14,142st Client Point: %5f\n", DataSet[14142 - 1].point);

	return 0;
}
