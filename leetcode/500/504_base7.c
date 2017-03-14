#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

char* convertToBase7(int num) {
    int sign = 1;
    char *p;
    char *pp;
    int len = 0;
    int i;

    if (num == 0)
        return "0";

    pp = calloc(sizeof(char) * 100, 1);
    p = pp;
    if (num < 0) {
        sign = -1;
        num = -num;
        pp[0] = '-';
        p++;
    }
    
    while (num) {
        p[len++] = num % 7+'0';
        num /= 7;
    }
    
    for (i=0; i<len/2; i++) {
        char t;
        t = p[i];
        p[i] = p[len-i-1];
        p[len-i-1] = t;
    }
    return pp;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

