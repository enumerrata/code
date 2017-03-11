#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isvowel(char a)
{ 
    return a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U';
}

char* reverseVowels(char* s) {
    int len=strlen(s);
    int i,j;
    char t;
    
    if (len <= 1)
        return s;
    
    for (i=0,j=len-1; i<j; ) {
        if (!isvowel(s[i]) && isvowel(s[j]))
            i++;
        else if (!isvowel(s[j]) && isvowel(s[i]))
            j--;
        else if (isvowel(s[i]) && isvowel(s[j])) {
            t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        } else {
            i++;
            j--;
        }
        //printf("%d %d\n", i,j);
    }
    return s;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

