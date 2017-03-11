#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool containsDuplicate(int* nums, int numsSize) {
    int i,j;
    
    if (numsSize <= 1)
        return false;
        
    for (i=0; i<numsSize-1; i++) {
        for (j=i+1; j<numsSize; j++)
            if (nums[i] == nums[j])
                return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

