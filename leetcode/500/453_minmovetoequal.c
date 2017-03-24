#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int minMoves(int* nums, int numsSize) {
    int i;
    int min = nums[0];
    int sum =0;
    
    for (i=0; i<numsSize; i++) {
        min = min > nums[i]? nums[i]:min;
    }
    for (i=0; i<numsSize; i++) {
        sum += nums[i] - min;
    }
    return sum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

