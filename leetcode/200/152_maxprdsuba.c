#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"


#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

int maxProduct(int* nums, int numsSize) {
    int maxprd = nums[0];
    int minprd = nums[0];
    int max1 = nums[0];
    int i;
    
    for (i=1; i<numsSize; i++) {
        int a = nums[i] * maxprd;
        int b = nums[i] * minprd;
        
        maxprd = MAX(MAX(a,b), nums[i]);
        minprd = MIN(MIN(a,b), nums[i]);
        max1 = MAX(max1, maxprd);

    }
    return max1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

