#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

#if 0
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
#else
int max(int a, int b)
{
    return a>b?a:b;
}

int maxProduct(int* nums, int numsSize) {
    int p=0,n=0,t;
    int i;
    int max1=INT_MIN;
    
    if (numsSize == 1)
        return nums[0];

    for (i=0; i<numsSize; i++) {
        if (nums[i] > 0) {
            if (p)
                p *= nums[i];
            else
                p = nums[i];
            n *= nums[i];
        } else if (nums[i] < 0) {
            t = p;
            p = nums[i] * n;
            if (t)
                n = nums[i] *t;
            else
                n = nums[i];
        } else {
            p = 0;
            n = 0;
        }
        //printf("%d %d \n", p, n);
        max1 = max(max(p,n), max1);
    }
    return max1;
}
#endif

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

