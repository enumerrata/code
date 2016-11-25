#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int firstUniqChar(char* s) {
    int i,j;
    int len = strlen(s);
    
    if (len == 0)
        return -1;
        
    if (len == 1)
        return 0;
        
    for (i=0; i<len; i++) {
        for (j=0; j<len; j++) {
            if (i == j)
                continue;
                
            if (s[i] == s[j])
                break;
        }
        if (j == len)
            return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

