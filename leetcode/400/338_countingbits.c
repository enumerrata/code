#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *p;
    int i,j=0;
    int limit = 1;
    
    p = malloc(sizeof(int) * (num +1));
    p[0] = 0;
    
    for (i=1; i<=num; i++) {
        
        if (i == limit) {
            limit *= 2;
            j=1;
            p[i] = 1;
        } else {
            p[i] = p[j++]+1;
        }
    }
    
    *returnSize = num+1;
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

