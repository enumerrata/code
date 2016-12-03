#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool ispal(char *s, int len)
{
    int i;
    
    for (i=0; i<len/2; i++) {
        if (s[i] != s[len-i-1])
            return false;
    }
    return true;
}

char* longestPalindrome_1(char* s) {
    int len = strlen(s);
    int i,j;
    int max=1;
    int pos=0;
    
    for (i=0; i<len; i++) {
        for (j=len-i; j>max; j--)
            if (ispal(s+i, j))
                break;
        if (j>max) {
            max = j;
            pos = i;
        }
    }
	//printf("%d %d \n", max, pos);

	char *p = malloc(len + 1);
	memcpy(p, s+pos, len);
	p[max] = '\0';
    
    return p;
}

char* longestPalindrome_g(char* s) {
    int longest = 1, length = strlen(s);
    char *start = s, *center = s;

    while (center + longest / 2 < s + length) {
        
        char* b = center, *e = center + 1;
        // count # of chars in the center
        // eg. in ...abbbba..., there are 4 b's in the center
        while(*b == *e) { 
            e++;
        } 
        
        center = e;
        
        // count # of steps we can take
        while(b > s && *(b - 1) == *e) {
            --b, e++;
        }

        // eg. in ...tcabbbbacp...
        // and length of cabbbbac is 8, e - b
        if(e - b > longest) { 
            longest = e - b; 
            start = b;
        }
    }
    
    return strndup(start, longest);
}

int main(int argc, char *argv[])
{
	printf("> %s \n",
	longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

	return 0;
}

