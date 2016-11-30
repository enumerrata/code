#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int i,j;
    
    if (numsSize < 2)
        return false;
        
    for (i=0; i<numsSize-1; i++) {
        for (j=i+1; (j<=i+k) && j<numsSize; j++) {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
	int a[] = {-1,-1}; 
	printf("> %d\n", containsNearbyDuplicate(a, 2, 2));

	return 0;
}

