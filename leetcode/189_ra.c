#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void rotate(int* nums, int numsSize, int k) {
    int *p;
    int i;
    
    p = malloc(numsSize * sizeof(int));
    
    memcpy(p, nums, sizeof(int) * numsSize);
    
    for (i=0; i<numsSize; i++) { 
        nums[(i + k) % numsSize] = p[i];
    }
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

