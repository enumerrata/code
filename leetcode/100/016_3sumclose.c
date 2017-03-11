#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int threeSumClosest(int* nums, int numsSize, int target) {
    int i,j,k,t;
    int v = nums[0] + nums[1] + nums[2];
    int min = abs(v - target);
    
    for (i=0;i<numsSize; i++)
        for(j=i+1; j<numsSize; j++) {
            int tt = nums[i] + nums[j];
            for(k=j+1; k<numsSize; k++) {
                
                if (j==i || j==k || k==i)
                    continue;
                
                t = tt + nums[k];
                if (abs(t -target) < min) {
                    min = abs(t-target);
                    v = t;
                }
                
            }
        }
    return v;
}

int main(int argc, char *argv[])
{
	int t[4] = {1,1,1,0 };
	printf("> %d \n", threeSumClosest(t, 4, 100));

	return 0;
}

