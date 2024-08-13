#include <stdio.h>
#include <stdlib.h>

typedef struct range {
	int StartIndex;
	int EndIndex;
} Range;

void MergeSort(int DataSet[], int StartIndex, int EndIndex);
void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex );

void MergeSort(int DataSet[], int StartIndex, int EndIndex)
{
    int Top1 = 0;
    int Top2 = 0;
    Range *Stack1 = NULL;
    Range *Stack2 = NULL;
    int IsUseStack1 = 1;
    int i = 0;
    int Left = 0, Right = 0, Middle = 0;
    int j = 0;

    Stack1 = (Range*)malloc(sizeof(Range) * (EndIndex - StartIndex + 1));
    Stack2 = (Range*)malloc(sizeof(Range) * (EndIndex - StartIndex + 1));

    for(i = StartIndex; i <= EndIndex; i++) {
        Stack1[Top1].StartIndex = i;
        Stack1[Top1].EndIndex = i;
	Top1++;
    }

    while(Top1 + Top2 > 1) {
	if(IsUseStack1) {
	    Top1--;
	    Right = Stack1[Top1].EndIndex;
	    Top1--;
	    Middle = Stack1[Top1].EndIndex;
	    Left = Stack1[Top1].StartIndex;
	    Merge(DataSet, Left, Middle, Right);
	    Stack2[Top2].StartIndex = Left;
	    Stack2[Top2].EndIndex = Right;
	    Top2++;
	} else {
	    Top2--;
	    Left = Stack2[Top2].StartIndex;
	    Middle = Stack2[Top2].EndIndex;
	    Top2--;
	    Right = Stack2[Top2].EndIndex;
	    Merge(DataSet, Left, Middle, Right);
	    Stack1[Top1].StartIndex = Left;
	    Stack1[Top1].EndIndex = Right;
	    Top1++;
	}
	if(IsUseStack1 && Top1 < 2) {
		if(Top1 == 1) {
			Top1--;
			Stack2[Top2].StartIndex = Stack1[Top1].StartIndex;
			Stack2[Top2].EndIndex = Stack1[Top1].EndIndex;
			Top2++;
		}
		IsUseStack1 = 0;
	} else if(!IsUseStack1 && Top2 < 2) {
		if(Top2 == 1) {
			Top2--;
			Stack1[Top1].StartIndex = Stack2[Top2].StartIndex;
			Stack1[Top1].EndIndex = Stack2[Top2].EndIndex;
			Top1++;
		}
		IsUseStack1 = 1;
	}
    }

    free(Stack1);
    free(Stack2);
}

void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex )
{
    int i;
    int LeftIndex  = StartIndex;
    int RightIndex = MiddleIndex + 1;
    int DestIndex  = 0;

    int* Destination = (int*) malloc( sizeof(int) * (EndIndex - StartIndex + 1) );
    
    while ( LeftIndex <= MiddleIndex && RightIndex <= EndIndex ) 
    {
	    if (DataSet[ LeftIndex ] < DataSet [RightIndex ]) 
        {
		    Destination[ DestIndex ] = DataSet[ LeftIndex ];
		    LeftIndex++;
	    } else {
		    Destination[ DestIndex ] = DataSet[ RightIndex];
		    RightIndex++;
	    }
	    DestIndex++;
    }

    while ( LeftIndex <= MiddleIndex ) 
	    Destination[ DestIndex++ ] = DataSet[ LeftIndex++ ];

    while ( RightIndex <= EndIndex )
        Destination[ DestIndex++ ] = DataSet[ RightIndex++ ];

    DestIndex = 0;
    for (i = StartIndex; i<=EndIndex; i++) 
    {
	    DataSet[i] = Destination[ DestIndex++ ];
    }

    free( Destination );
}

int main( void )
{
    int DataSet[] = {334, 6, 4, 2, 3, 1, 5, 117, 12, 34};
    int Length = sizeof DataSet / sizeof DataSet[0];    
    int i = 0;

    MergeSort( DataSet, 0, Length-1 );

    for ( i=0; i<Length; i++ )
    {
        printf("%d ", DataSet[i]);
    }

    printf("\n");

    return 0;
}
