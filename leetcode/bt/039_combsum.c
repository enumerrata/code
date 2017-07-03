#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
void find(int *l, int siz, int target, int *stack, int top, int cursum,   int **p, int *rets, int **cols)
{
	int i;

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

	for (i=0; i<siz; i++) {
        if (top > 0 && l[i] < stack[top-1]) 
			continue;
        stack[top++] = l[i];
        find(l, siz, target, stack, top, cursum + l[i], p, rets, cols);
        top--;
	}

	
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	int stack[1000];
	int **p = malloc(sizeof(int *) * 1000);
	int top = 0;
	int cursum = 0;

	*columnSizes = malloc(sizeof(int) * 1000);
	*returnSize = 0;

	find(candidates, candidatesSize, target, stack, top, cursum,   p, returnSize, columnSizes);
	
	return p;
}
#else
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void find(int *c, int casiz, int target, int *stack, int top, int **p, int *csiz, int *siz)
{
	int i;

	if (target <= 0) {
		if (target == 0) {
			csiz[*siz] = top;
			p[*siz] = malloc(sizeof(int) * top);
			memcpy(p[*siz], stack, top*sizeof(int));
			*siz += 1;
		}
		return;
	}

	for (i=0; i<casiz; i++) {
		if (top && c[i] < stack[top-1])
			continue;
		stack[top++] = c[i];
		find(c, casiz, target-c[i], stack, top, p, csiz, siz);
		top--;
	}

}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	int stack[1000];
	int **p = malloc(sizeof(int *) * 1000);

	*columnSizes = malloc(sizeof(int) * 1000);
	*returnSize = 0;

	find(candidates, candidatesSize, target, stack, 0, p, *columnSizes, returnSize);
	
	return p;
}

#endif

int main(int argc, char *argv[])
{
	int a[] = {2, 3, 6, 7};
	int **p;
	int *col;
	int ret = 0;
	int i,j;

	p = combinationSum(a, 4, 7, &col, &ret);
	for (i=0; i<ret; i++) {
		for (j=0; j<col[i]; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	printf("> \n");

	return 0;
}

