#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>


int cmp(const void *p1, const void *p2)
{
	return *(int *)p1 > *(int *)p2;
}

void dfs(int* nums, int numsSize, int** columnSizes, int* returnSize, int * stack, int top, int **p) {
    int i;

    if (numsSize == top) {
        int count = 0;
        (*columnSizes)[*returnSize] = 0;
        for (i = 0 ; i < top ; i++) {
            (*columnSizes)[(*returnSize)] += stack[i];
        }
        p[(*returnSize)] = malloc((*columnSizes)[(*returnSize)]*sizeof(int));
        for (i = 0 ; i < top ; i++) {
            if (stack[i] == 1) 
				p[(*returnSize)][count++] = nums[i];
        }
        (* returnSize)++;
        return;
    }

    stack[top++] = 0;
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, p);
    top--;
    for (i = 0 ; i < top ; i++) {
        if (stack[i] == 0 && nums[i] == nums[top]) {
            return;
        }
    }
    stack[top++] = 1;
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, p);
    top--;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int size = pow(2, numsSize);
    int **p = malloc(sizeof(int *) * size);
    (* columnSizes) = malloc(sizeof(int) * size);
    int stack[numsSize], top = 0;
    
	qsort(nums, numsSize, sizeof(int), cmp);
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, p);
	return p;
}

int main(int argc, char *argv[])
{
	int a[] = {1,2,2};
	int **p;
	int *csiz;
	int siz;
	int i,j;

	p = subsetsWithDup(a, 3, &csiz, &siz);

	for (i=0; i<siz; i++) {
		for (j=0; j<csiz[i]; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	

	printf("> \n");

	return 0;
}

