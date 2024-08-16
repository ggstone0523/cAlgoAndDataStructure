#include "Answer.h"

int compareCoin(const void* first, const void* second) {
	if(((coinInfo*)first)->coin < ((coinInfo*)second)->coin) {
		return 1;
	} else if(((coinInfo*)first)->coin > ((coinInfo*)second)->coin) {
		return -1;
	} else {
		return 0;
	}
}

void findMinimumChange(int changeMoney, int allCoinCount, coinInfo* coins, int size, int* minimum) {
	int i = 0;

	if(changeMoney == 0) {
		if((*minimum > allCoinCount) || (*minimum == -1)) {
			*minimum = allCoinCount;
			for(i = 0; i < size; i++) {
				coins[i].answerCount = coins[i].perCount;
			}	
		}
		return;
	}

	if((*minimum <= allCoinCount) && (*minimum != -1))
		return;

	for(i = 0; i < size; i++) {
		if(changeMoney >= coins[i].coin) {
			coins[i].perCount++;
			findMinimumChange(changeMoney - coins[i].coin, allCoinCount + 1, coins, 
					size, minimum);
			coins[i].perCount--;
		}
	}
	
}

int main(int argc, char** argv) {
	coinInfo* coins;
	int size = 0;
	int minimum = -1;
	int price = 0;
	int pay = 0;
	int i = 0;

	printf("동전의 가짓수를 입력하세요 : ");
	scanf("%d", &size);
	coins = (coinInfo*)malloc(sizeof(coinInfo) * size);

	for(i = 0; i < size; i++) {
		printf("[%d] 번째 동전의 단위를 입력하세요 : ", i);
		scanf("%d", &coins[i].coin);
	}
	qsort(coins, size, sizeof(coinInfo), compareCoin);

	printf("물건 가격을 입력하세요 : ");
	scanf("%d", &price);
	printf("손님이 지불한 돈은 얼마입니까 : ");
	scanf("%d", &pay);
	findMinimumChange(pay - price, 0, coins, size, &minimum);

	printf("minimum change's count is %d\n", minimum);
	for(i = 0; i < size; i++) {
		printf("%8d원 : %d개\n", coins[i].coin, coins[i].answerCount);
	}

	free(coins);

	return 0;
}
