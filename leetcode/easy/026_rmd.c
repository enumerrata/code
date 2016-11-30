#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize) {
	int i,j;
	int t;
	
	if (numsSize <= 1)
		return numsSize;

	t = nums[0];	
	for (i=1,j=1; i<numsSize; i++) {
		if (t != nums[i]) {
			nums[j++] = nums[i];
			t = nums[i];
		}
	}

	return j;
    
}

int main(int argc, char *argv[])
{



	return 0;
}

