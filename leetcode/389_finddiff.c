#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char findTheDifference(char* s, char* t) {
    int map[26] = { 0 };
    
    while (*s) {
        map[*s++ - 'a']++;
    }
    
    while (*t) {
        if (map[*t - 'a'] <= 0)
            return *t;
        map[*t++ - 'a']--;
    }
    
    return true;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

