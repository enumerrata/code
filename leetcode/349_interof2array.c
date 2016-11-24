#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void addin(int n, int *nums, int *len)
{
    int i;
    
    for (i=0; i<*len; i++) { 
        if (nums[i] == n)
            return;
    }
    
    nums[*len] = n;
    *len += 1;
}

bool isin(int n, int *nums, int len)
{
    int i;
    for (i=0; i<len; i++) {
        if (nums[i] == n)
            return true;
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *p; 
    int len = 0;
    int i;
    
    p = malloc(sizeof(int) * nums1Size);
    
    for (i=0; i<nums1Size; i++) { 
        if (isin(nums1[i], nums2, nums2Size))
            addin(nums1[i], p, &len);
    }
    *returnSize = len;
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

