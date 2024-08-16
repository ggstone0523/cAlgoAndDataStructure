#include <stdio.h>
#include <stdlib.h>

typedef struct CoinInfo {
	int coin;
	int perCount;
	int answerCount;
} coinInfo;

void findMinimumChange(int changeMoney, int allCoinCount, coinInfo* coins, int size, int* minimum);
int compareCoin(const void* first, const void* second);
