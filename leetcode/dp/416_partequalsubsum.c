#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

bool canPartition(int* nums, int numsSize) {
	int i,j;
	int sum=0;
	bool *p;

	for (i=0; i<numsSize; i++) 
		sum += nums[i];

   	if (sum%2) 
		return false;

	p = calloc(sum/2+1, sizeof(bool));
	p[0] = true;
	for (i=0; i<numsSize; i++) {
		for (j=sum/2; j>=nums[i]; j--)
			p[j] = p[j] || p[j-nums[i]];
		if (p[sum/2])
		    return true;
	}

#if 0
	for (i=0; i<sum/2+1; i++) {
		printf("%d ", p[i]);
	}
#endif

	return p[sum/2];
}

int main(int argc, char *argv[])
{
	int a[]={1,5,11,5};

	printf("> %d\n", canPartition(a, 4));

	return 0;
}

