#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool valid(int *a, int n)
{
	int loc = a[n-1];
	int i;

	for (i = 0; i < n-1; i ++) {
		if(a[i] == loc)
			return false;
		else if(abs(a[i]-loc) == abs(i-n+1))
			return false;
	}
	return true;
}

char **convert(int *stack, int top) {
	char **p;
	int i;

	p = malloc(sizeof(char *) * top);
	for (i=0; i<top; i++) {
		p[i] = malloc(sizeof(char) *(top+1));
		memset(p[i], '.', sizeof(char) *top);
		p[i][stack[i]] = 'Q';
		p[i][top] = '\0';
	}
	return p;
}

void gen(int n, int *stack, int top, char ***p, int *siz)
{
	int i;

	if (valid(stack, top)) {
		if (top == n) {
			p[*siz] = convert(stack, top);
			*siz += 1;
			return;
		}
	} else {
		return;
	}

	for (i=0; i<n; i++) {
		stack[top++] = i;
		gen(n, stack, top, p, siz);
		top--;
	}

}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize) {
	int a[n+1];
	int cnt=0;
	char ***p;

	p = malloc(sizeof(char *) * 1000);

   	gen(n, a, 0, p, returnSize); 
	return p;
}

int main(int argc, char *argv[])
{
	int siz;
	char ***p;
	int i,j;

	p=solveNQueens(9, &siz);
	for (i=0; i<siz; i++) {
		for (j=0; j<9; j++) {
			printf("%s", p[i][j]);
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}

