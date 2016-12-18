#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int size = pow(2, numsSize);
    int i,j;
    int **p = malloc(sizeof(int *) * size);
    
    *columnSizes = malloc(sizeof(int) * size);
    
    *returnSize = size;
    for (i=0; i<size; i++) {
        int len = 0;
        p[i] = malloc(sizeof(int) * numsSize);
        for (j=0; j<numsSize; j++) {
            if (i & (1<<j)) {
                p[i][len++] = nums[j];
            }
            
        }
        (*columnSizes)[i] = len;
    }
    
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

