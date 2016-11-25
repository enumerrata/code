#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int map[26] = { 0 };
    
    while (*magazine) {
        map[*magazine++ - 'a']++;
    }
    
    while (*ransomNote) {
        if (map[*ransomNote - 'a'] <= 0)
            return false;
        map[*ransomNote++ - 'a']--;
    }
    return true;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

