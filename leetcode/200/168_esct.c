#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


char* convertToTitle(int n) {
    char *p;
    int i = 0,j;
    
    p = malloc(n/26 + 2);

    while (n > 0) {
        if ((n % 26) == 0) {
            p[i++] = 'Z';
        } else {
            p[i++] = n % 26 + 'A' - 1;
        }
		n = (n-1) / 26;
    }
    
    p[i] = '\0';
    for (j=0; j<i/2; j++) {
        char t;
        t = p[j];
        p[j] = p[i-1-j];
        p[i-1-j] = t;
    }
    
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

