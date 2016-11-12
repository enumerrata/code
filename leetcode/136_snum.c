#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int singleNumber(int* nums, int numsSize) {
    int num = 0, i;
    
    if (!numsSize)
        return 0;

    for (i=0; i<numsSize; i++) {
        num ^= nums[i];         
    }
    return num;    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

