#include "Answer.h"

void Swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSortIter(int DataSet[], int Left, int Right) {
	int First = 0;
	int Pivot = 0;
	int End = 0;
	void Swap(int* a, int* b);

	Push(Left);
	Push(Right);

	while(!StackIsEmpty()) {
		Right = Pop();
		Left = Pop();
		First = Left;
		End = Right;
		Pivot = DataSet[Left];
		Left++;
		while(Left < Right) {
			while(DataSet[Left] <= Pivot && Left < Right)
				Left++;
		
			while(DataSet[Right] >= Pivot && Left <= Right)
				Right--;
		
			if(Left < Right) {
				Swap(&DataSet[Left], &DataSet[Right]);
			}
		}
		Swap(&DataSet[First], &DataSet[Right]);
		if(First < Right - 1) {
			Push(First);
			Push(Right-1);
		}
		if(Right + 1 < End) {
			Push(Right+1);
			Push(End);
		}
	}
}
