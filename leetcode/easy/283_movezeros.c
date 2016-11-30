#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void moveZeroes(int* nums, int numsSize) {
    int i=0;
    int j=0;
    
    for (i=0; i<numsSize; i++) {
        if (nums[i]) { 
            nums[j++] = nums[i];
        }
    }
    
    while (j < numsSize)
        nums[j++] = 0;
        
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

