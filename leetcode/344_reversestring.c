#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char* reverseString(char* s) {
    int len=strlen(s);
    int i;
    char t;
    
    if (len <= 1)
        return s;
    
    for (i=0; i<len/2; i++) {
        t = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = t;
    }
    return s;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

