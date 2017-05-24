#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"


int max(int a, int b)
{
    return a>b?a:b;
}

/* keep rob & norob max value */
int rob(int* nums, int numsSize) {
    int r = 0;
    int nr = 0;
    int t;
    int i;
    
    for (i=0; i<numsSize; i++) {
        t = r;
        r = nr + nums[i];
        nr = max(t, nr);
    }
 
    return max(r, nr);   
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

