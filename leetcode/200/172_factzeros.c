#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int trailingZeroes(int n) {
    
    if (n < 5)
        return 0;
    
    return n/5 + trailingZeroes(n/5);
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

