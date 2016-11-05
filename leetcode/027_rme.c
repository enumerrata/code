#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int removeElement(int* nums, int numsSize, int val) {
	int i,j;

	if (!numsSize)
		return numsSize;

	for (i=0,j=0; j<numsSize; j++) {
		if (nums[j] != val)
			nums[i++] = nums[j];
	}

	return i;
}

int main(int argc, char *argv[])
{



	return 0;
}

