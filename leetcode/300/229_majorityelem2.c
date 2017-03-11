#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int a=0, b=0;
    int cnta=0, cntb=0;
    int i;
    
    for (i=0; i<numsSize; i++) {
        if (nums[i] == a)
            cnta++;
        else if (nums[i] == b)
            cntb++;
        else if (!cnta) {
            cnta = 1;
            a = nums[i];
        } else if (!cntb) {
            cntb = 1;
            b = nums[i];
        } else {
            cnta--;
            cntb--;
        }
    }
    cnta = cntb = 0;
    for (i=0; i<numsSize; i++) {
        if (nums[i] == a)
            cnta++;
        else if (nums[i] == b)
            cntb++;
    }
    
    *returnSize = 0;
    int *p = malloc(sizeof(int) * 2);
    if (cnta > numsSize/3) {
        p[*returnSize] = a;
        *returnSize += 1;
    }
     
    if (cntb > numsSize/3) {
        p[*returnSize] = b;
        *returnSize += 1;
    }  
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

