#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int countSegments(char* s) {
    int i;
    int cnt=0;
    int out=1;
    
    for (i=0; i<strlen(s); i++) {
        if (out && s[i] != ' ') {
            cnt++;
            out = 0;
        } else if (!out && s[i] == ' ') {
            out = 1;
        }
    }
    return cnt;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

