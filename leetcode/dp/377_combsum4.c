#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int combinationSum4(int* nums, int numsSize, int target) {
    int *p;
    int i,j;
    
    p = calloc(target+1, sizeof(int));
    p[0] = 1;
    
    for (i=1; i<=target; i++) {
        for (j=0; j<numsSize; j++) {
            if (nums[j] <= i)
                p[i] += p[i-nums[j]];
        }
    }
    
    return p[target];
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

