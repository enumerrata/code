#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int firstMissingPositive(int* nums, int numsSize) {
    int i, t;
    for (i = 0 ; i < numsSize ; i++) {
        int idx = nums[i] - 1;
        if (idx > -1 && idx < numsSize && nums[idx] != nums[i]) {
            t = nums[idx];
            nums[idx] = nums[i];
            nums[i] = t;
            i--;
        }
    }
    for (i = 0 ; i < numsSize ; i++) {
        if (nums[i] != i+1) {
            break;
        }
    }
    return i+1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

