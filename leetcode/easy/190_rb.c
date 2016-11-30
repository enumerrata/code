#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

uint32_t reverseBits(uint32_t n) {
    int temp = 0;
    int i;
    
    for (i=0; i<32; i++) {
        if (n & (1<<i ))
            temp |= 1<<(32-i-1);
    } 
    return temp;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

