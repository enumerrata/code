#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
int cmp(const void *p1, const void *p2)
{
	return *(int *)p1 > *(int *)p2;
}

void find(int *l, int start, int siz, int target, int *stack, int top, int cursum,   int **p, int *rets, int **cols)
{
	int i,pre=0;

	if (cursum > target)
		return;
	
	if (cursum == target) {
		p[*rets] = malloc(sizeof(int) * top);
		memcpy(p[*rets], stack, top*sizeof(int));
		(*cols)[*rets] = top;
		*rets += 1;
		//for (i=0; i<top; i++)
		//	printf("%d ", stack[i]);
		//printf("\n");
		return;
	}

	for (i=start; i<siz; i++) {
        if (pre == l[i]) {
            continue;
        } else {
            pre = l[i];
        }
        stack[top++] = l[i];
        find(l, i+1, siz, target, stack, top, cursum + l[i], p, rets, cols);
        top--;
	}

	
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	int stack[1000];
	int **p = malloc(sizeof(int *) * 1000);
	int top = 0;
	int cursum = 0;

	*columnSizes = malloc(sizeof(int) * 1000);
	*returnSize = 0;

	qsort(candidates, candidatesSize, sizeof(int), cmp);

	find(candidates, 0, candidatesSize, target, stack, top, cursum,   p, returnSize, columnSizes);
	
	return p;

}
#else
int cmp(const void *p1, const void *p2)
{
	return *(int *)p1 > *(int *)p2;
}

void find(int *l, int start, int siz, int target, int *stack, int top, int **p, int *rets, int **cols)
{
	int i,pre=0;

	if (target < 0) 
		return;
	
	if (target == 0) {
		p[*rets] = malloc(sizeof(int) * top);
		memcpy(p[*rets], stack, top*sizeof(int));
		(*cols)[*rets] = top;
		*rets += 1;
		//for (i=0; i<top; i++)
		//	printf("%d ", stack[i]);
		//printf("\n");
		return;
	}

	for (i=start; i<siz; i++) {
        if (pre == l[i]) {
            continue;
        } else {
            pre = l[i];
        }
        stack[top++] = l[i];
        find(l, i+1, siz, target-l[i], stack, top, p, rets, cols);
        top--;
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	int stack[1000];
	int **p = malloc(sizeof(int *) * 1000);
	int top = 0;

	*columnSizes = malloc(sizeof(int) * 1000);
	*returnSize = 0;

	qsort(candidates, candidatesSize, sizeof(int), cmp);

	find(candidates, 0, candidatesSize, target, stack, top,p, returnSize, columnSizes);
	
	return p;
}
#endif

int main(int argc, char *argv[])
{
	int a[] = {10, 1, 2, 7, 6, 1, 5};
	int **p;
	int *col;
	int ret = 0;
	int i,j;

	p = combinationSum2(a, 7, 8, &col, &ret);
	for (i=0; i<ret; i++) {
		for (j=0; j<col[i]; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	printf("> \n");
	printf("> \n");

	return 0;
}

