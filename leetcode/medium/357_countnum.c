#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int countNumbersWithUniqueDigits(int n) {
    int i = 2;
    int sum = 10;
    int t = 9;
    int j = 9;
    
    if (!n)
        return 1;
    
    while (i<=n) {
        t = t * j;
        sum += t;
        j -= 1;
        i++;
    }
    
    return sum;  
}


int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

