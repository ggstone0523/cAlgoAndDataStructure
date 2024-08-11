#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "BoyerMoore.h"

#define MAX_BUFFER 512

int main(int argc, char** argv)
{
    char* FilePath;
    FILE* fp;

    char  Text[MAX_BUFFER];
    char* Pattern;
    int   PatternSize = 0;
    int   Line        = 0;
    int* BadCharTable = NULL;
    int* GoodSuffTable = NULL;
    int* PosOfBorder = NULL;
    
    if ( argc < 3 )
    {
        printf("Usage: %s <FilePath> <Pattern>\n", argv[0] );
        return 1;
    }

    FilePath = argv[1];
    Pattern  = argv[2];

    PatternSize = strlen( Pattern );

    if ( (fp = fopen( FilePath, "r"))  == NULL )
    {
        printf("Cannot open file:%s\n", FilePath);
        return 1;
    } 

    BadCharTable = (int*)calloc(128, sizeof( int )); 
    GoodSuffTable  = (int*)calloc( PatternSize + 1, sizeof( int ) );
    PosOfBorder = (int*)calloc( PatternSize + 1, sizeof( int ) );
    BuildBCT( Pattern, PatternSize, BadCharTable );    
    BuildGST( Pattern, PatternSize, PosOfBorder, GoodSuffTable );

    print_table(BadCharTable, 128);
    print_GoodSuffTable_table(GoodSuffTable, PosOfBorder, Pattern, PatternSize+1);

    while ( fgets( Text, MAX_BUFFER, fp ) != NULL )
    {
        int Position = 
            BoyerMoore( Text, strlen(Text), 0, Pattern, PatternSize, 
			    GoodSuffTable, PosOfBorder, BadCharTable );
        
        Line++;

        if ( Position >= 0 ) 
        {
            printf("line:%d, column:%d : %s", Line, Position+1, Text);
        }
    }

    fclose( fp );
    free ( PosOfBorder );
    free ( GoodSuffTable  );
    free ( BadCharTable );

    return 0;
}
