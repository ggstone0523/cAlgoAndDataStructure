#include "Sudoku.h"

int main() {
	int sudokuData[9][9] = {{0, 4, 7, 6, 0, 9, 0, 0, 0},
		{0, 2, 0, 0, 0, 0, 8, 0, 0},
		{5, 0, 0, 0, 1, 0, 0, 0, 7},
		{2, 0, 8, 4, 0, 3, 0, 1, 0},
		{4, 3, 6, 5, 2, 1, 9, 7, 8},
		{0, 1, 0, 7, 0, 6, 3, 0, 4},
		{1, 0, 0, 0, 7, 0, 0, 0, 3},
		{0, 0, 9, 0, 0, 0, 0, 4, 0},
		{0, 0, 0, 8, 0, 4, 6, 9, 0}};
	int i = 0, j = 0;
	
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			printf("%d ", sudokuData[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	solveSudoku(sudokuData);

	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			printf("%d ", sudokuData[i][j]);
		}
		printf("\n");
	}
}
