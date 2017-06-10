#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int max(int a, int b)
{
	return a>b?a:b;
}
/* i-j player1 max*/
bool PredictTheWinner(int* nums, int numsSize) {
	int len = numsSize;
	int **p;
	int i,j;
	int *a = nums;

	p = malloc(sizeof(int *) * (len+1));
	for (i=0; i<len+1; i++) {
		p[i] = malloc(sizeof(int) *(len+1));
		for (j=0; j<len+1; j++) {
			if (i == j)
				p[i][j] = nums[i];
			else
				p[i][j] = 0;
		}
	}

	for (i=len-1; i>=0; i--) {
		for (j=i+1; j<len; j++) {
				p[i][j] = max(nums[i]-p[i+1][j], nums[j]-p[i][j-1]);
		}
	}

#if 0
	for (i=0; i<len+1; i++) {
		for (j=0; j<len+1; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
#endif
	return p[0][len-1] >= 0;
}
int main(int argc, char *argv[])
{
	//int a[] = {1, 5, 233, 7};
	int a[] = {1, 1};

	printf("> %d\n", PredictTheWinner(a, 2));

	return 0;
}

