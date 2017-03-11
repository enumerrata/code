#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int cmp( const void* a, const void* b)
{
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );
	
	return int_a > int_b;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	int **p = malloc(sizeof(int *) * 1000);
	int remain = 0;
	int sum;

	int a,b,c,d;

	qsort(nums, numsSize, sizeof(int), cmp);
	*returnSize = 0;

	for (a=0; a<numsSize-3; a++) {
		for (b=a+1; b<numsSize-2; b++) {
			remain = target - nums[a] - nums[b];

			c = b + 1;
			d = numsSize - 1;

			while (c < d) {
				sum = nums[c] + nums[d];
				if (sum == remain) {
                    p[(* returnSize)] = malloc(sizeof(int)*4);
                    p[(* returnSize)][0] = nums[a];
                    p[(* returnSize)][1] = nums[b];
                    p[(* returnSize)][2] = nums[c];
                    p[(* returnSize)][3] = nums[d];
                    (* returnSize)++;
                    while (c < d && nums[c] == nums[c+1])
                        c++;
                    while (c < d && nums[d] == nums[d-1])
                        d--;
				} 
				if (sum > remain) {
					d--;
				} else {
					c++;
				}
				//printf(">> %d %d %d %d %d %d\n", a,b,c,d,sum,remain);
			}

            while (b < numsSize - 2 && nums[b] == nums[b+1])
                b++;
		}

        while (a < numsSize - 3 && nums[a] == nums[a+1])
            a++;
	}

   	return p; 
}

int main(int argc, char *argv[])
{
	int **p;
	int siz;
	int i;

	int a[] = {1, 0, -1, 0, -2, 2}; 

	p = fourSum(a, 6, 0, &siz);
	for (i=0; i<siz; i++) {
		printf("%d %d %d %d\n", p[i][0], p[i][1], p[i][2], p[i][3]);
	}


	printf("> \n");

	return 0;
}

