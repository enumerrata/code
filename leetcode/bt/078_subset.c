#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#if 0
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int size = pow(2, numsSize);
    int i,j;
    int **p = malloc(sizeof(int *) * size);
    
    *columnSizes = malloc(sizeof(int) * size);
    
    *returnSize = size;
    for (i=0; i<size; i++) {
        int len = 0;
        p[i] = malloc(sizeof(int) * numsSize);
        for (j=0; j<numsSize; j++) {
            if (i & (1<<j)) {
                p[i][len++] = nums[j];
            }
            
        }
        (*columnSizes)[i] = len;
    }
    
    return p;
}
#else

void gen(int *nums, int nsiz, int start, int *stack, int top, int **p, int *csiz, int *siz)
{
	int i,j;
	int t;

	p[*siz] = malloc(nsiz*sizeof(int));
	memcpy(p[*siz], stack, sizeof(int)*top);
	csiz[*siz] = top;
	*siz += 1;
	
	for (i=start; i<nsiz; i++) {
		stack[top++] = nums[i];
		gen(nums, nsiz, i+1, stack, top, p, csiz, siz);
		top--;
	}
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
	int len = pow(2, numsSize);
	int **p;
	int stack[numsSize];
	int top=0;

	*returnSize = 0;
	(*columnSizes) = malloc(sizeof(int) * len);
	p = malloc(sizeof(int *)*len);

	gen(nums, numsSize, 0, stack, top, p, *columnSizes, returnSize);

	return p;
}

#endif

int main(int argc, char *argv[])
{

	int a[] = {1,2,2};
	int **p;
	int *csiz;
	int siz;
	int i,j;

	p = subsets(a, 3, &csiz, &siz);

	printf("> %d\n", siz);
	for (i=0; i<siz; i++) {
		for (j=0; j<csiz[i]; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	return 0;
}

