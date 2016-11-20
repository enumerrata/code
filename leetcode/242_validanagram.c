#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isAnagram(char* s, char* t) {
    int map[26]={0};
    int i;
    
    while (*s) { 
        map[*s++ - 'a']++;
    }
    
    while (*t) {
        map[*t++ - 'a']--;
    }
    
    for (i=0; i<26; i++)
        if (map[i])
            return false;
    
    return true;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

