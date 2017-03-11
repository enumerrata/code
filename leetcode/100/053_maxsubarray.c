#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int maxsum = nums[0];
    int i;
    
    for (i=1; i<numsSize; i++) {
        if (max < 0)
            max = 0;    
        
        max += nums[i];
        if (maxsum < max) {
            maxsum = max;
        }
    }
    return maxsum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

