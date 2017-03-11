#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
   	int **p = malloc(sizeof(int *)*n); 
	int s=0, e=n-1; // col
	int ss=0, ee=n-1; // row
	int i,j;
	int len=1;

	for (i=0; i<n; i++)
		p[i] = malloc(sizeof(int) * n);
    
	while (e>=s && ee>=ss) {
		for (i=ss,j=s; j<=e; j++) {
			p[i][j] = len++;
			//printf(">> %d ", len);
		}
		//printf("\n");
		for (i=ss+1,j=e; i<=ee; i++) {
			p[i][j] = len++;
			//printf("%d ", matrix[i][j]);
		}
		//printf("\n");
		for (i=ee,j=e-1; j>=s; j--) {
			p[i][j] = len++;
			//printf("%d ", matrix[i][j]);
		}
		//printf("\n");
		for (i=ee-1,j=s; i>ss; i--) {
			p[i][j] = len++;
			//printf("%d ", matrix[i][j]);
		}
		//printf("\n");

		s++; e--;
		ss++; ee--;
	}

	return p;
}

int main(int argc, char *argv[])
{
	int **p;
	int i;
	int n = 1;

	p = generateMatrix(n);
	for (i=0; i<n*n; i++)
		printf("%d ", p[0][0]);

	printf("> \n");

	return 0;
}

