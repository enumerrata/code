#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "tree.h"


void reverse(char *s, int i, int j) {
    char t;
    
    while (i < j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; j--;
    }
}

char* reverseStr(char* s, int k) {
    int i=0;
    int len = strlen(s);
    
    while (i<len) {
        reverse(s, i, i+k-1>=len?len-1:i+k-1);
        i += 2*k;
    }
    return s;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

