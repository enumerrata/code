#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int candy(int* ratings, int ratingsSize) {
    int nums[ratingsSize];
    int i;
    int sum=0;

    nums[0] = 1;
    for (i=1; i<ratingsSize;i++) {
        if (ratings[i] > ratings[i-1]) {
            nums[i] = nums[i-1]+1;
        } else {
            nums[i] = 1;
        }
    }
    
    for (i=ratingsSize-2; i>=0; i--) {
        if (ratings[i] >  ratings[i+1] && nums[i] <= nums[i+1]) {
            nums[i] = nums[i+1]+1;
        }
        sum += nums[i];
    }   
    sum += nums[ratingsSize-1];
    return sum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

