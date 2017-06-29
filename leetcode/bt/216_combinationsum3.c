#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

#if 0
void recurFind(int k, int start, int target, int **p, int **cols, int *siz, int *st, 
	int top, int sum)
{
	int i;

	if (sum > target || top > k)
		return ;
	
	if (sum == target && top == k) {
		(*cols)[*siz] = k;		
		p[*siz] = malloc(sizeof(int) * k); 
		memcpy(p[*siz], st, k*sizeof(int));
		*siz += 1;
		return ;
	}

	for (i=start; i<=9; i++) {
        st[top++] = i;
        recurFind(k, i + 1, target, p, cols, siz, st, top, sum + i);
        top--;
	}

}

int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) {
	int **p;
	int stack[1000];
	int top = 0;

	p = malloc(sizeof(int *) * 1000);
	(*columnSizes) = malloc(sizeof(int) * 1000);
	*returnSize = 0;
	recurFind(k, 1, n, p, columnSizes, returnSize, stack, top, 0);

	return p;
}
#else
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int gen(int *nums, int *used, int cid, int cval, int siz, int value, int **p, int *len) 
{
	int i;

	if (siz < 0 || cval > value)
		return;

	if (siz == 0) {
		if (cval == value) {
			int top=0;
			p[*len] = malloc(sizeof(int) * 10);
			for (i=0; i<9; i++) {
				if (used[i])
					p[*len][top++] = i+1;
			}
			*len +=  1;
		}
		return;
	}

	for (i=cid; i<9; i++) {
		cval += nums[i];
		used[i] = 1;
		gen(nums, used, i+1, cval, siz-1, value, p, len);
		cval -= nums[i];
		used[i] = 0;
	}

}
int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) {
	int a[]={1,2,3,4,5,6,7,8,9};
	int used[9]={0};
	int **p;
	int i;

	*returnSize = 0;
	p = malloc(sizeof(int*) * 1000);
	gen(a, used, 0, 0, k, n, p, returnSize);

	*columnSizes = malloc(sizeof(int) * *returnSize);
	for (i=0; i<*returnSize; i++) {
		(*columnSizes)[i] = k;
	}

	return p;
}
#endif

int main(int argc, char *argv[])
{
	int **p;
	int *cols;
	int siz;
	int i,j;

	p = combinationSum3(2, 18, &cols, &siz);
	for (i=0; i<siz; i++) {
		for (j=0; j<cols[i]; j++)
			printf("%d ", p[i][j]);

		printf("\n");
	}


	printf("> \n");

	return 0;
}

