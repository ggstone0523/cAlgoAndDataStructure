#include "Answer.h"

void BubbleSortUpgrade(int DataSet[], int Length) {
	int i, j, temp, DoSwap;
	
	for(i = 0; i < Length-1; i++) {
		DoSwap = 0;
		for(j = 0; j < Length-(i+1); j++) {
			if(DataSet[j] > DataSet[j+1]) {
				temp = DataSet[j];
				DataSet[j] = DataSet[j+1];
				DataSet[j+1] = temp;
				DoSwap = 1;		
			}
		}
		if(DoSwap == 0)
			break;
	}
}
