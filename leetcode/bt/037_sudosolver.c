#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

bool issolve(char **board, int rsiz, int csiz)
{
	int i,j;

	for (i=0; i<rsiz; i++) {
		for (j=0; j<csiz; j++) {
			if (board[i][j] == '.')
				return false;
		}
	}
	printf("--\n");
	return true;
}

bool isValid(char **board, int x, int y)  
{  
	int i, j;  

	for (i = 0; i < 9; i++)  
		if (i != x && board[i][y] == board[x][y])  
			return false;  
	for (j = 0; j < 9; j++)  
		if (j != y && board[x][j] == board[x][y])  
			return false;  
	for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)  
		for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)  
			if (i != x && j != y && board[i][j] == board[x][y])  
				return false;  
	return true;  
}  

bool solve(char **board, int rsiz, int csiz)
{
	int i,j,k;

	for (i=0; i<rsiz; i++) {
		for (j=0; j<csiz; j++) {

			if (board[i][j] == '.') {
				for (k='1'; k<='9'; k++) {
					board[i][j] = k;
					if (isValid(board, i, j) && solve(board, rsiz, csiz))
						return true;
					board[i][j] = '.';
				}
				return false;
			}
		}
	}

	return true;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	solve(board, boardRowSize, boardColSize);
}

int main(int argc, char *argv[])
{

	char a[]="..9748...";
	char b[]="7........";
	char c[]=".2.1.9...";
	char d[]="..7...24.";

	char e[]=".64.1.59.";
	char f[]=".98...3..";
	char g[]="...8.3.2.";
	char h[]="........6";
	char i[]="...2759..";

	char *p[] ={a,b,c,d,e,f,g,h,i};
	int k,j;


	solveSudoku(p, 9, 9);
	for (k=0; k<9; k++) {
		for (j=0; j<9; j++) {
			printf("%c ", p[k][j]);
		}
		printf("\n");
	}

	return 0;
}

