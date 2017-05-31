#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

#if 0
int min(int a, int b)
{
    return a<b?a:b;
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int **copy;
    int max = 0;
    int i,j;
    
    if (!matrixRowSize || !matrixColSize)
        return 0;
    
    copy = malloc(sizeof(int *)* matrixRowSize);
    
    for (i=0; i<matrixRowSize; i++) {
        copy[i] = malloc(sizeof(int)*matrixColSize);
        copy[i][0] = matrix[i][0] - '0';
        max = max > copy[i][0] ? max: copy[i][0];
    }
    
    for (j=0; j<matrixColSize; j++) {
        copy[0][j] = matrix[0][j] - '0';
        max = max > copy[0][j] ? max: copy[0][j];
    }
    
    for (i=1; i<matrixRowSize; i++)
        for (j=1; j<matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                copy[i][j] = min(copy[i-1][j], min(copy[i][j-1], copy[i-1][j-1])) + 1;
                max = max > copy[i][j] ? max:copy[i][j];
            } else {
                copy[i][j] = 0;
            }
        }
    return max*max;
    
}
#endif

int max(int a, int b)
{
    return a>b?a:b;
}

int min(int a, int b)
{
    return a>b?b:a;
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int i,j;
    char **a = matrix;
    int mx = 0;
    int mm;
    
    for (i=0; i<matrixRowSize; i++)
        for (j=0; j<matrixColSize; j++) {
            if (i && j) {
                mm = min(min(a[i-1][j-1], a[i-1][j]), a[i][j-1]);
                if (a[i][j] == '1')
                    a[i][j] = mm + 1;
                else
                    a[i][j] = 0;
            } else {
                if (a[i][j] >= '0')
                    a[i][j] -= '0';
            }
            mx = max(mx, a[i][j]);
        }
    return mx*mx;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

