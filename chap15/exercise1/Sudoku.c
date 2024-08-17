#include "Sudoku.h"

int checkSudokuCond(int sudokuData[9][9], int x, int y, int num) {
	int i = 0, j = 0;
	int boxX = 0, boxY = 0;

	for(i = 0; i < 9; i++) {
		if(sudokuData[i][y] == num) {
			return 0;
		}
	}
	
	for(i = 0; i < 9; i++) {
		if(sudokuData[x][i] == num) {
			return 0;
		}
	}
	
	boxX = (x / 3) * 3;
	boxY = (y / 3) * 3;
	for(i = boxX; i < boxX + 3; i++) {
		for(j = boxY; j < boxY + 3; j++) {
			if(sudokuData[i][j] == num) {
				return 0;
			}
		}
	}

	return 1;
}

int solveSudoku(int sudokuData[9][9]) {
	int i = 0, j = 0, k = 0;
	int retVal = 0;

	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			if(sudokuData[i][j] == 0) {
				for(k = 1; k <= 9; k++) {
					if(checkSudokuCond(sudokuData, i, j, k)) {
						sudokuData[i][j] = k;
						retVal = solveSudoku(sudokuData);
						if(retVal == 1)
							return 1;
						sudokuData[i][j] = 0;			
					}
				}
				return 0;
			}
		}
	}

	return 1;
}
