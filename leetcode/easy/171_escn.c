#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int titleToNumber(char* s) {
    int sum = 0;
    
    if (*s == '\0')
        return 0;
    
    while (*s) {
        sum = sum * 26 + (*s - 'A' + 1);
        s++;
    }
    
    return sum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

