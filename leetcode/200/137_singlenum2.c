#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int singleNumber(int* nums, int numsSize) {
    int one=0;
    int two=0;
    int three=0;
    
    int i;
    for (i=0; i<numsSize; i++) {
        two ^= one & nums[i];
        one ^= nums[i];
        three = two & one;
        one &= ~three;
        two &= ~three;
    }
    return one;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

