#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int max(int a, int b) {
    return a>b?a:b;
}


int lengthOfLIS(int* nums, int numsSize) {
    
    if (numsSize == 0)
        return 0;
        
    int a[numsSize];
    int i,j;
    int max1=1;

    a[0] = 1;
    for (i=1; i<numsSize; i++) {
        a[i] = 1;
        for (j=0; j<i; j++) {
            if (nums[i] > nums[j])
                a[i] = max(a[j] + 1, a[i]);
        }
        max1 = max(a[i], max1);
    }

    return max1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

