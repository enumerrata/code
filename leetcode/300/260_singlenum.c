#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
	int i;
	unsigned int sum=0;
	int bit;
	unsigned int a = 0, b = 0;

	for (i=0; i<numsSize; i++) {
		sum ^= nums[i];
	}

	bit = (sum & (sum - 1) ) ^ sum;
	//printf("%d %d\n", sum, bit);

	for (i=0; i<numsSize; i++) {
		if (nums[i] & bit) {
			a ^= nums[i];
		} else {
			b ^= nums[i];
		}
	}

	int *p = malloc(sizeof(int) * 2);
	p[0] = a;
	p[1] = b;
	*returnSize = 2;
   
   	return p; 
}

int main(int argc, char *argv[])
{
	int a[] = {1, 2, 1, 3, 2, 5};
	int siz;
	int *p;

	p = singleNumber(a, 6, &siz);

	printf(">  %d %d\n", p[0], p[1]);

	return 0;
}

