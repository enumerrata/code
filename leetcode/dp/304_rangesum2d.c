#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

typedef struct {
	int **p; 
} NumMatrix; 

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
	NumMatrix *p;
	int **t;
	int i,j;

	p = malloc(sizeof(NumMatrix));
	p->p = malloc(sizeof(int *) * matrixRowSize);
	t = p->p;

	for (i=0; i<matrixRowSize; i++) {
		t[i] = malloc(sizeof(int) * matrixColSize);
		for (j=0; j<matrixColSize; j++) {
			if (!i && !j) {
				t[i][j] = matrix[i][j];
			} else if (!i) {
				t[i][j] = t[i][j-1] + matrix[i][j];
			} else if (!j) {
				t[i][j] = t[i-1][j] + matrix[i][j];
			} else {
				t[i][j] = t[i-1][j] + t[i][j-1] + matrix[i][j] - t[i-1][j-1];
			}
		}
	}
   
   	return p; 
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
	int cnt=0;
	int area=0;

	area = obj->p[row2][col2];

	if (row1) {
		cnt++;
		area -= obj->p[row1-1][col2];
	}

	if (col1) {
		cnt++;
		area -= obj->p[row2][col1-1];
	}

	if (cnt == 2) {
		area += obj->p[row1-1][col1-1];
	}

   	return area; 
}

void numMatrixFree(NumMatrix* obj) {
    
}


/**
 * Your NumMatrix struct will be instantiated and called as such:
 * struct NumMatrix* obj = numMatrixCreate(matrix, matrixRowSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 * numMatrixFree(obj);
 */

int main(int argc, char *argv[])
{
	int a[] = {3,0,1,4,2};
	int b[] = {5,6,3,2,1};
	int c[] = {1,2,0,1,5};
	int d[] = {4,1,0,1,7};
	int e[] = {1,0,3,0,5};
	int *t[] = {a,b,c,d,e};
	NumMatrix *p;
	int aa[] = {2,1,4,3};

	p= numMatrixCreate(t, 5, 5);
	printf("> %d \n", numMatrixSumRegion(p, 2,1,4,3));
	printf("> %d \n", numMatrixSumRegion(p, 1,1,2,2));
	printf("> %d \n", numMatrixSumRegion(p, 1,2,2,4));

	return 0;
}
