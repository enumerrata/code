#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int rangeBitwiseAnd(int m, int n) {
    int shift = 0;
    
    while (m != n) {
        m >>= 1;
        n >>= 1;
        shift++;
        
    }
    return m<<shift;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

