#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isSubsequence(char* s, char* t) {
    
    while (*s && *t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    
    return !*s;
}

/* LCS */

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

