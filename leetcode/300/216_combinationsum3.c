#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


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

