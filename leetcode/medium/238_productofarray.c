#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int *p = malloc(sizeof(int) * numsSize);
	int i;
	int mul;

	p[0] = 1;
	mul = nums[0];
	for (i=1; i<numsSize; i++) {
		p[i] = mul;
		mul *= nums[i];
	}

	//printf("> %d %d %d %d\n", p[0],p[1],p[2],p[3]);
	mul = nums[numsSize-1];
	for (i=numsSize-2; i>=0; i--) {
		p[i] = p[i] * mul;
		mul *= nums[i];
	}
	*returnSize = numsSize;
   
   	return p; 
}

int main(int argc, char *argv[])
{
	int a[] = {1,2,3,4};
	int *b; 
	int siz;

	b = productExceptSelf(a, 4, &siz);

	printf("> %d %d %d %d\n", b[0],b[1],b[2],b[3]);

	return 0;
}

