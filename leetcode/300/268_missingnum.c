#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int missingNumber(int* nums, int numsSize) {
    int i;
    int r=numsSize;
    
    for (i=0; i<numsSize; i++) {
        r ^= nums[i];
        r ^= i;
    }

    return r;
}
int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

