#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


bool isUgly(int num) {
    
    while (num >= 2 && !(num % 2))
        num /= 2;
    
    while (num >= 3 && !(num % 3))
        num /= 3;
    
    while (num >= 5 && !(num % 5))
        num /= 5;
    
    return num == 1;
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

