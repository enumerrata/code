#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// a,b,c,d
// a,b;  a,b,c=3

int strStr(char* haystack, char* needle) {
	int i,j;
	int len1;
	int len2;

	if (!*haystack && !*needle)
		return 0;

	len1 =  strlen(needle);
	len2 =  strlen(haystack);
	if (len2 < len1)
		return -1;
	
	for (i=0; i<len2-len1+1; i++) {
		for (j=0; j<len1; j++) {
			if (haystack[i+j] != needle[j])
				break;
		}
		if (j == len1)
			return i;
	}

    
	return -1;
}

int main(int argc, char *argv[])
{

	printf("%d", strStr("ab", "c"));
	return 0;
}

