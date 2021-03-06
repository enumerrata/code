#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
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

bool visit(int *list, int *siz, int v)
{
	int i;

	for (i=0; i<*siz; i++) {
		if (list[i] == v)
			return true;
	}

	list[*siz] = v;
	*siz += 1;

	return false;
}

void per(int n, int *a, int l, int r, int **p, int *siz) 
{
	int i;

	if (l == r) {
		p[*siz] = malloc(sizeof(int) * n);
		memcpy(p[*siz], a, sizeof(int) * n);
		*siz += 1;
	} else {
		int *visited = malloc(sizeof(int) * (r-l+1));
		int len = 0;
		for (i=l; i<=r; i++) {

			if (!visit(visited, &len, a[i])) {
				swap(&a[l], &a[i]);
				per(n, a, l+1, r, p, siz);
				swap(&a[l], &a[i]);
			}
		}
	}

}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
	int n = 1;
	int i;
	int siz = 0;
	int **p;

	for (i=1; i<=numsSize; i++)
		n *= i;

	p = malloc(sizeof(int *) * n);
	per(numsSize, nums, 0, numsSize-1, p, &siz);

	*returnSize = siz;

   	return p; 
}
#else
int cmp(const void *p1, const void *p2)
{
	return *(int *)p1 > *(int *)p2;
}

void swap(int *a, int *b)
{
	int t;
	t = *a; *a = *b; *b = t;
}

void gen(int *nums, int len, int i, int j, int **p, int *siz)
{
	int k;
	int *pp;
	if (i==j-1) {
		p[*siz] = malloc(sizeof(int) * len); 
		memcpy(p[*siz], nums, len*sizeof(int));
		*siz +=  1;
		return;
	}

	for (k = i; k < j; k++) {
		if (i != k && nums[i] == nums[k]) 
			continue;
		//printf("%d %d\n", i, k);
		swap(&nums[i], &nums[k]);
		pp = malloc(sizeof(int) * len);
		memcpy(pp, nums, len*sizeof(int));
		gen(pp, len, i+1, j, p, siz);
	}
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
	int **p;
    
	p = malloc(sizeof(int *) * 10000);
	*returnSize = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	gen(nums, numsSize, 0, numsSize, p, returnSize);

	return p;
}
#endif

int main(int argc, char *argv[])
{
    int str[] = {2,2,1,1};
	int siz;
	int **p;
	int i;

    p = permuteUnique(str, 4, &siz);

	for (i=0; i<siz; i++) {
		printf("%d %d %d %d\n", p[i][0], p[i][1], p[i][2], p[i][3]);
	}

	return 0;
}

