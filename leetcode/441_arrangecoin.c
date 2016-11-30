#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int arrangeCoins(int n) {
    int i = 0;
    long long  sum = 0;
    
    while (sum <= n) {
        i++;
        sum +=  i;
    }
    
    return i-1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

