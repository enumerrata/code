#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
	int n = matrixRowSize;
	int row;
	int col;

	for (row=0; row<n/2; row++) {
		for (col=row; col<n-row-1; col++) {
			int tmp = matrix[row][col];
			matrix[row][col] = matrix[n-1-col][row];
			matrix[n-1-col][row] = matrix[n-1-row][n-1-col];
			matrix[n-1-row][n-1-col] = matrix[col][n-1-row];
			matrix[col][n-1-row] = tmp;
			if (col==1) {
				//printf("%d %d %d %d\n", matrix[row][col], matrix[n-1-col][row],
					//matrix[n-1-row][n-1-col], matrix[col][n-1-row]);
			}
		}
	}
    
}

int main(int argc, char *argv[])
{
#if 0
	int a[4]={1,2,3,4}; 
	int b[4]={5,6,7,8}; 
	int c[4]={9,10,11,12}; 
	int d[4]={13,14,15,16}; 
	int *p[4] = {a,b,c,d};

	int i,j;

	rotate(p, 4, 4);

	for (i=0; i<4; i++) {
		printf("%02d %02d %02d %02d\n", p[i][0], p[i][1], p[i][2], p[i][3]);
	}
#else

	int a[]={1,2}; 
	int b[]={3,4}; 
	int *p[2] = {a,b};

	int i,j;

	rotate(p, 2, 2);

	for (i=0; i<2; i++) {
		printf("%02d %02d \n", p[i][0], p[i][1]);
	}
#endif

	return 0;
}

