#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isPowerOfTwo(int n) {
    int i;
    int cnt = 0;
    
    if (n < 0)
        return false;
        
    for (i=0; i<32; i++) { 
        if (n & (1<<i))
            cnt++;
    }
    return cnt == 1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

