#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

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

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

