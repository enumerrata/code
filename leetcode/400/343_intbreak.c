#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int integerBreak(int n) {
    int prod = 1;
    
    if (n==2) return 1;
    if (n==3) return 2;
    
    while (n > 4) {
        prod *= 3;
        n -= 3;
    }
    
    return prod * n;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

