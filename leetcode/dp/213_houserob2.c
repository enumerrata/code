#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"


int max(int a, int b)
{
    return a>b?a:b;
}

int rob1(int* nums, int numsSize) {
    int a = 0;
    int b = nums[0];
    int i;
    
    for (i=1; i<numsSize; i++) {
        int t;
        t = b;
        b = max(a+nums[i], b);
        a = t;
    }
    return max(a,b);
}

int rob(int* nums, int numsSize) {
   	return max(rob1(nums+1, numsSize-1), rob1(nums, numsSize-1));
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

