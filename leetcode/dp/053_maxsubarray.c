#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int maxsum = nums[0];
    int i;
    
    for (i=1; i<numsSize; i++) {
        if (max < 0)
            max = 0;    
        
        max += nums[i];
        if (maxsum < max) {
            maxsum = max;
        }
    }
    return maxsum;
}
#endif

int maxSubArray(int* nums, int numsSize) {
    int sum=nums[0];
    int i;
    int max=sum;
    
    for (i=1; i<numsSize; i++) {
        if (sum < 0) {
            if (nums[i] < 0)
                sum = nums[i]>sum?nums[i]:sum;
            else
                sum = nums[i];
        } else 
            sum += nums[i];
        max = max>sum?max:sum;
        //printf("%d %d\n", max, sum);
    }
    
    return max;
}
int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

