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


void gen(int n, int *stack, int top, int *cnt)
{
	int i;

	if (valid(stack, top)) {
		if (top == n) {
#if 0
			for (i=0; i<n; i++) {
				printf("%d ", stack[i]);
			}
			printf("\n");
#endif
			*cnt += 1;
			return;
		}
	} else {
		return;
	}

	for (i=0; i<n; i++) {
		stack[top++] = i;
		gen(n, stack, top, cnt);
		top--;
	}

}

int totalNQueens(int n) {
	int a[n+1];
	int cnt=0;

   	gen(n, a, 0, &cnt); 
	return cnt;
}

int main(int argc, char *argv[])
{
	int siz;

	totalNQueens(4);

	return 0;
}

