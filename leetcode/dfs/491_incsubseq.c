#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#if 0
void pr(int *stack, int top, int **p, int *csiz, int *siz)
{
	int find = 0;
	int i=0,j=0;
	int *pp;
	unsigned int sum = 0;

	for (j=0; j<top; j++) {
		sum = (sum << 4) + (sum << 8) + stack[j] - sum;
	}
	for (i=0; i<*siz; i++) {
		if (top == csiz[i] && p[i][top] == sum) {
				find = 1;
		}
	}
	//printf("%d %d %d %d\n", i,j, top, find);
	if ( !*siz || !find ) {
		pp = malloc(sizeof(int) * (top+1));
		p[*siz] = pp;
		memcpy(p[*siz], stack, sizeof(int) * top);
		p[*siz][top] = sum;
		csiz[*siz] = top;
		*siz += 1;
	}
}
#else
void pr(int *stack, int top, int **p, int *csiz, int *siz)
{
	int find = 0;
	int i=0,j=0;

	for (i=0; i<*siz; i++) {
		if (top == csiz[i]) {
			for (j=0; j<top; j++) {
				if (p[i][j] != stack[j]) {
					break;
				}
			}
			if (j == top)
				find = 1;
		}
	}
	//printf("%d %d %d %d\n", i,j, top, find);
	if ( !*siz || !find ) {
		p[*siz] = malloc(sizeof(int) * top);
		memcpy(p[*siz], stack, sizeof(int) * top);
		csiz[*siz] = top;
		*siz += 1;
	}
}
#endif
void gen(int *nums, int nsiz, int cur, int *stack, int top, int **p, int *csiz, int *siz)
{
	int i;

	for (i=cur; i<nsiz; i++) {
		if (!top || nums[i] >= stack[top-1]) {
			stack[top++] = nums[i];
			if (top > 1)
				pr(stack, top, p, csiz, siz);
			gen(nums, nsiz, i+1, stack, top, p, csiz, siz);
			top--;
		}
	}

}

int** findSubsequences(int* nums, int numsSize, int** columnSizes, int* returnSize) {
	int stack[numsSize];
	int **p;
    
	*returnSize = 0;
	*columnSizes = malloc(sizeof(int) * 100000);
	p = malloc(sizeof(int *) * 100000);

	gen(nums, numsSize, 0, stack, 0, p, *columnSizes, returnSize);

	return p;
}

int main(int argc, char *argv[])
{
	//int a[] = {1,3,5,7};
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int **p;
	int siz;
	int *csiz;
	int i,j;


	p = findSubsequences(a, 15, &csiz, &siz);

	printf("%d \n", siz);
#if 0
	for (i=0; i<siz; i++) {
		printf("\n");
		for (j=0; j<csiz[i]; j++) {
			printf("%d ", p[i][j]);
		}
	}
#endif

	return 0;
}

