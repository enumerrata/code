#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int *a = malloc(sizeof(int) * 20100);
    int len = 0;
    int lens = strlen(s);
    int lenp = strlen(p);
    
    int i;
    int mapp[26] = {0};
    int maps[26] = {0};
    
    *returnSize = 0;
    
    for (i=0; i<lenp; i++) {
        mapp[p[i] - 'a']++;
        maps[s[i] - 'a']++;
    }
    
    for (i=0; i<lens-lenp+1; i++) {
        if (!memcmp(mapp, maps, 26*4)) {
            a[*returnSize] = i;
            *returnSize += 1;
        }
        maps[s[i] - 'a']--;
        maps[s[i+lenp] - 'a']++;
    }
    return a;
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

