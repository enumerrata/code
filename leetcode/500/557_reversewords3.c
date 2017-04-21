#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

void reverse(char *s, int i, int j)
{
    char t;
    
    while (j > i) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; j--;
    }
}


char* reverseWords(char* s) {
    int i,j,t=0;
    int out=1;
    
    while (s[t]) {
        if (out && s[t] != ' ') {
            out = 0;
            i = t;
        } else if (out == 0 && s[t] == ' ') {
            j = t-1;
            reverse(s, i, j);
            out = 1;
        }
        t++;
    }
    reverse(s, i, t-1);
        
    return s;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

