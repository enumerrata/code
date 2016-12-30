#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int *p = malloc(sizeof(int) * numsSize);
    int len=0;
    int cnt = 0;
    int i;
    
    for (i=0; i<numsSize; i++) {
        int t = abs(nums[i]) - 1;
        if (nums[t] < 0) {
            p[len++] = t+1;
        } else {
            nums[t] = -nums[t];
        }
    }
    *returnSize = len;
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

