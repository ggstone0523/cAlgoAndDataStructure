#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <stdio.h>

int  BoyerMoore(char* Text, int TextSize, int Start, char* Pattern, int PatternSize,
		int* GoodSuffTable, int* PosOfBorder, int* BadCharTable);
void BuildGST( char* Pattern, int PatternSize, int* Suffix, int* GST );
void BuildBCT( char* Pattern, int PatternSize, int* BST );
int  Max( int A, int B);
void print_table(int* table, int table_size);
void print_GoodSuffTable_table(int* table, int* PosOfBorder, char* Pattern, int table_size);

#endif
