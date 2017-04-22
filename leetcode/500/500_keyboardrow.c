#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getline_(char c, char **tab)
{
    int i,j;
    
    if (c < 'a')
        c = c-'A' + 'a';
    for (i=0; i<3; i++)
        for (j=0; j<strlen(tab[i]); j++)
            if (tab[i][j] == c)
                return i;
    return 0;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    char *tab[3];
    char **p;
    int i,j;
    int line = 0;
    int match = 1;
    
    tab[0] = "asdfghjkl";
    tab[1] = "zxcvbnm";
    tab[2] = "qwertyuiop";
    *returnSize = 0;
    
    p = malloc(sizeof(char *) * wordsSize);
    
    for (i=0; i<wordsSize; i++) {
        line = -1;
        match = 1;
        for (j=0; j<strlen(words[i]); j++) {
            if (line == -1)
                line = getline_(words[i][j], tab);
            else if (line != getline_(words[i][j], tab)) {
                match = 0;
                break;
            }
        }
        if (match) {
            p[*returnSize] = strdup(words[i]);
            *returnSize += 1;
        }
    }
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

