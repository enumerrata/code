#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

int findPeakElement(int* nums, int numsSize) {
    int i;
    
    if (numsSize == 1)
        return 0;
    if (nums[numsSize-1] > nums[numsSize-2])
        return numsSize-1;
    
    for (i=1; i<numsSize-1; i++) {
        if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
            return i;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

