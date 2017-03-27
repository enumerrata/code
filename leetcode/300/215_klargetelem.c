#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int comparefn( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) 
		 return 0;
     else if ( int_a > int_b ) 
		 return -1;
     else 
		 return 1;
}


int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), comparefn);
    return nums[k-1];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

