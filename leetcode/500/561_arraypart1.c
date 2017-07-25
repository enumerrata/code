#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int cmpint( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) 
		 return 0;
     else if ( int_a < int_b ) 
		 return -1;
     else 
		 return 1;
}


int arrayPairSum(int* nums, int numsSize) {
    int i;
    int sum=0;
    
    if (!numsSize)
        return 0;
    
    qsort(nums, numsSize, sizeof(int), cmpint);
    for (i=0; i<numsSize; i+=2)
        sum += nums[i];
    
    return sum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

