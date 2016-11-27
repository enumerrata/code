#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int longestPalindrome(char* s) {
    int map[127] = {0};
    int i;
    int count = 0;
    int t=0;
    
    while (*s) {
        map[*s++]++;
    }
    
    for (i='A'; i<='z'; i++) {
        if (map[i] > 0) {
            count += map[i] / 2 * 2;
            if (map[i] % 2)
                t = 1;
        }
    }
    
    return count + t;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

