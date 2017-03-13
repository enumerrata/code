#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

int findComplement(int num) {
    int bit = 0;
    int i;
    long long mask;
    
    for (i=0; i<31; i++) {
        if (num & (1<<i))
            bit = i;
    }
    
    mask = (1<<(bit+1)) - 1;
    return ~num & mask; 
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

