#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "tree.h"

int minSubArrayLen(int s, int* nums, int numsSize) {
    int start = 0;
    int e = 0;
    
    int min = INT_MAX;
    int sum = 0;
    
    while (start < numsSize && e < numsSize) {
        while (sum<s && e <numsSize) {
            sum += nums[e++];
        }
        
        while (sum>=s && start<numsSize) {
            min = min > e-start? e-start:min;
            sum -= nums[start++];
        }
    }
    return min == INT_MAX? 0:min;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

