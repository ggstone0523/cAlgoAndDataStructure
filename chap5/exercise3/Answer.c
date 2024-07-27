#include "Answer.h"

void Swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int PartitionUpgrade(int DataSet[], int Left, int Right) {
    int First = Left;
    int Center = (Left + Right) / 2;
    int Pivot = DataSet[Center];
    void Swap(int* a, int* b);

    Swap(&DataSet[First], &DataSet[Center]);

    ++Left;

    while( Left <= Right )
    {
        while(DataSet[Left] <= Pivot && Left < Right)
            ++Left;

        while(DataSet[Right] >= Pivot && Left <= Right)
            --Right;

        if(Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}
