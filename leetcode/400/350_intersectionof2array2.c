#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>



    
void addin(int n, int *nums, int *len)
{
    int i;
    
    nums[*len] = n;
    *len += 1;
}

int isin(int n, int *nums, int len)
{
    int i;
    for (i=0; i<len; i++) {
        if (nums[i] == n)
            return i;
    }
    return -1;
}

void rm(int i, int *nums, int *len)
{
    int j;
    
    for (j=i+1; j<*len; j++)
        nums[j-1] = nums[j];
    *len -= 1;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *p; 
    int len = 0;
    int i;
    int pos;
    
    p = malloc(sizeof(int) * nums1Size);
    
    for (i=0; i<nums1Size; i++) { 
        pos = isin(nums1[i], nums2, nums2Size);
        if (pos >= 0) {
            rm(pos, nums2, &nums2Size);
            addin(nums1[i], p, &len);
            //printf(" %d\n", nums1[i]);

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

