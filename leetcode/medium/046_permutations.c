#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
void per(int n, int *a, int l, int r, int **p, int *siz) 
{
	int i;

	if (l == r) {
		p[*siz] = malloc(sizeof(int) * n);
		memcpy(p[*siz], a, sizeof(int) * n);
		*siz += 1;
	} else {
		for (i=l; i<=r; i++) {
			swap(&a[l], &a[i]);
			per(n, a, l+1, r, p, siz);
			swap(&a[l], &a[i]);
		}
	}

}

int** permute(int* nums, int numsSize, int* returnSize) {
	int n = 1;
	int i;
	int siz = 0;
	int **p;

	for (i=1; i<=numsSize; i++)
		n *= i;

	p = malloc(sizeof(int *) * n);
	per(numsSize, nums, 0, numsSize-1, p, &siz);

	*returnSize = n;

   	return p; 
}

int main(int argc, char *argv[])
{
    int str[] = {1,2,3};
	int siz;
	int **p;
	int i;

    p = permute(str, 3, &siz);

	for (i=0; i<siz; i++) {
		printf("%d %d %d \n", p[i][0], p[i][1], p[i][2]);
	}

	return 0;
}

