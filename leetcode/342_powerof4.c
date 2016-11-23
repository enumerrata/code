#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isPowerOfFour(int num) {
    
    if (num < 0)
        return false;
        
    while (num >= 4 && num % 4 == 0) { 
        num /= 4;
    }
    return num == 1;

}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

