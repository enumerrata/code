#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *p = malloc(sizeof(int) * numsSize);
    int len = 0;
    int i;
    
    for (i=0; i<numsSize; i++)
        nums[(nums[i] - 1)%numsSize] += numsSize;
        
    for (i=0; i<numsSize; i++) {
        //printf("%d ", nums[i]);
        if (nums[i] <= numsSize)
            p[len++] = i + 1;
    }
    *returnSize = len;
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

