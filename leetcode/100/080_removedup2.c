#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int removeDuplicates(int* nums, int numsSize) {
    int i;
    int len = 2;
    
    if (numsSize <= 2)
        return numsSize;
    
    for (i=2; i<numsSize; i++) {
        if (nums[i] > nums[len - 2]) {
            nums[len++] = nums[i];
        }
    }
    return len;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

