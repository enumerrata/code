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
     else if ( int_a < int_b ) 
		 return -1;
     else 
		 return 1;
}



void wiggleSort(int* nums, int numsSize) 
{
    int *p;
    int i;
    
    int s = (numsSize+ 1) >> 1;
    int t = numsSize;
    
    qsort(nums, numsSize, sizeof(int), comparefn);
    p = malloc(sizeof(int) * numsSize);
    
    for (i=0; i<numsSize; i++) {
        p[i] = (i & 1) == 0 ?  nums[--s] : nums[--t];
    }
    for (i=0; i<numsSize; i++) {
        nums[i] = p[i];
    }
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

