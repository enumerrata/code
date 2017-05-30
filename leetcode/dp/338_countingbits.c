#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if 0
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
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /* remove lower 0s */ 
int* countBits(int num, int* returnSize) {
    int i,t;
    int *p;
    
    p = calloc(num+1, sizeof(int));
    *returnSize = num + 1;
    
    p[0] = 0;
    p[1] = 1;
    for (i=2; i<num+1; i++) {
        t = i;
        while ((t%2) == 0) {
            t = t >>1;
        }
        p[i] = p[t-1] + 1;
    }
    
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

