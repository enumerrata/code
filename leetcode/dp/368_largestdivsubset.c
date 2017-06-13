#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int max(int a, int b)
{
    return a>b?a:b;
}

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

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    int i,j;
    int a[numsSize+1];
	int t[numsSize+1];
    int *p;
    int siz = 0;
	int max=0, id=0;
    
    p = malloc(sizeof(int) * numsSize);
	*returnSize = 0;
    
    memset(a, 0, sizeof(a));
	qsort(nums, numsSize, sizeof(int), comparefn);
    for (i=0; i<numsSize; i++) {
		a[i] = 1;
		t[i] = -1;
        for (j=0; j<i; j++) {
            if (nums[i] % nums[j] == 0)
                if (a[j] + 1 > a[i]) {
                    a[i] = a[j]+1;
                    t[i] = j;
                }
        }
		if (a[i] > max) {
			max = a[i];
			id = i;	
		}
    }

	printf("%d %d %d \n", t[0], t[1], t[2]);
	printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);

	while (id != -1) {
		p[(*returnSize)++] = nums[id];
		id = t[id];
	}
    return p;
}

int main(int argc, char *argv[])
{
	int a[] = {3,4,16,8};
	int siz;
	int *p;
	int i;

	printf("> %p\n", p=largestDivisibleSubset(a, 3, &siz));

	for (i=0; i<siz; i++) {
		printf("%d \n", p[i]);
	
	}

	return 0;
}

