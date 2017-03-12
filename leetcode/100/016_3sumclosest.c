#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"


void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int comparefn( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) 
		 return 0;
     else if ( int_a < int_b ) 
		 return -1;
     else 
		 return 1;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k, min = INT_MAX, minsum;

	qsort(nums, numsSize, sizeof(int), comparefn);

    for (i = 0 ; i < numsSize - 2 ; i++) {
        j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            int diff = abs(sum - target);
            if (diff < min) {
                minsum = sum;
                min = diff;
            }
            if (min == 0) {
                return minsum;
            }
            sum > target ? k-- : j++;
        }
    }
    return minsum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

