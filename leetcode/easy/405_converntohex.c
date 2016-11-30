#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char* toHex(int num) {
    char *p = malloc(sizeof(char) * 10);
    int len = 0;
    int i;
    char t;
    unsigned int n;
    
    if (!num) { 
        p[0] = '0';
        p[1] = '\0';
        return p;
    }
    
    if (num < 0)
        n = 0xffffffff + num + 1;
    else
        n = num;
    
    while (n) {
        p[len++] = (n % 16) >= 10 ? (n%16) - 10 + 'a' : (n%16) + '0';
        n /= 16;
    }

	//printf("%c %c\n", p[0], p[1]);
    
    for (i=0; i<len/2; i++) {
        t = p[i];a
        p[i] = p[len-i-1];
        p[len-i-1] = t;
    }
    p[len] = '\0';
    return p;
}

int main(int argc, char *argv[])
{
	printf(">%s \n", toHex(-2));

	return 0;
}

