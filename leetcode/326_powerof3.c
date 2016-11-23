#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isPowerOfThree(int n) {
        
    while (n >= 3 && n % 3 == 0) { 
        n /= 3;
    }
    return n == 1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

