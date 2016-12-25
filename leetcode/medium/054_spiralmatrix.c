#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *p = malloc(sizeof(int) * matrixRowSize * matrixColSize);
	int r=matrixRowSize;
	int c=matrixColSize;
	int s=0, e=c-1; // col
	int ss=0, ee=r-1; // row
	int i,j;
	int len=0;
    
	while (e>s && ee>ss) {
		for (i=ss,j=s; j<=e; j++) {
			p[len++] = matrix[i][j];
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
		for (i=ss+1,j=e; i<=ee; i++) {
			p[len++] = matrix[i][j];
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
		for (i=ee,j=e-1; j>=s; j--) {
			p[len++] = matrix[i][j];
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
		for (i=ee-1,j=s; i>ss; i--) {

			p[len++] = matrix[i][j];
			printf("%d ", matrix[i][j]);
		}
		printf("\n");

		s++; e--;
		ss++; ee--;
	}

	if (e == s) {
		for (j=e,i=ss; i<=ee; i++)
			p[len++] = matrix[i][j];
	} else if (ee == ss) {
		for (j=s,i=ss; j<=e; j++)
			p[len++] = matrix[i][j];
	}

	return p;
}

int main(int argc, char *argv[])
{
	int a[] = {1,2,3,4};
	int b[] = {5,6,7,8};
	int c[] = {9,10,11,12};
	int d[] = {12,13,14,15};
	int *p[] = {a,b,c,d}; 
	int *pp;
	int i;
	
	pp = spiralOrder(p, 1,4);
	for (i=0; i<16; i++)
		printf("%d ", pp[i]);
	printf("> \n");

	return 0;
}

