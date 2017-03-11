#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int countBattleships(char** board, int boardRowSize, int boardColSize) {
    int i,j;
    int cnt=0;
    
    for (i=0; i<boardRowSize; i++)
        for (j=0; j<boardColSize; j++) {
            if (board[i][j] == 'X') {
                if (!(i>0 && board[i-1][j] == 'X')
                    && !(j>0 && board[i][j-1] == 'X') )
                    cnt++;
            }
        }
    
    return cnt;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

