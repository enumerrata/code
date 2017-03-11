#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i=0;
    int j=0;
    int r;
    int *p = malloc(sizeof(int) * 2);
    
    for (i=0; i<numsSize-1; i++) {
        r = target - nums[i];
        for (j=i+1; j<numsSize; j++)
            if (nums[j] == r) {
                p[0] = i;
                p[1] = j;
                return p;
            }
    }

    return NULL;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

