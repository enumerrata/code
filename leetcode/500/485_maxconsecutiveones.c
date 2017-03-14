#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0;
    int cnt = 0;
    int i;
    
    for (i=0; i<numsSize; i++) {
        if (nums[i] != 1) {
            max = cnt > max ? cnt:max;
            cnt = 0;
        } else {
            cnt++;
        }
    }
    
    return cnt > max ? cnt : max;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

