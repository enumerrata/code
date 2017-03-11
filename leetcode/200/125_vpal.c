#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    char *p; 
    int i,j=0;
    int len = strlen(s);
    
    if (len <= 1)
        return true;
        
    p = malloc(len+1);
    
    for (i=0; i<len; i++) {
        if (isupper(s[i]))
            p[j++] = s[i] - 'A' +'a';
        else if (isalnum(s[i]))
            p[j++] = s[i];
    } 
    
    len = j;
    for (i=0; i<len/2; i++) {
        if (p[i] != p[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

