#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int findDuplicate(int* nums, int numsSize)
{
    int arr[numsSize];
    int i;

    memset(arr, 0, sizeof(arr));

    for (i = 0; i < numsSize; i++) {
        if (arr[nums[i]] == 1) {
            return nums[i];
        }
        arr[nums[i]] = 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

