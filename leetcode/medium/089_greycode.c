#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//https://en.wikipedia.org/wiki/Gray_code
int* grayCode(int n, int* returnSize) {
    int siz=pow(2, n);
    int *p = malloc(sizeof(int) * siz);
    int i;
    
    *returnSize = siz;
    
    for (i=0; i<siz; i++)
        p[i] = i ^ (i>>1); 
    
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

