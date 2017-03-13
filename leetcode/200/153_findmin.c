#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

int findMin(int* nums, int numsSize) {
    int l = 0;
    int r = numsSize - 1;
    
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[l] > nums[m]) { /* right side is sorted */
            r = m;
        } else if (nums[r] < nums[m]) { /* left side is sorted */
            l = m + 1;
        } else { /* the sub-array is not rotated */
            r = m;
        }
    }
    return nums[l];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

