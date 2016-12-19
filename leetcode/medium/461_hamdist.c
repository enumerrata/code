#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int hammingDistance(int x, int y) {
    int z = x ^ y;
    int cnt=0;
    
    while (z) {
        z = z&(z-1);
        cnt++;
    }
    
    return cnt;
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

