#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int maxProduct(char** words, int wordsSize) {
    int *p = malloc(sizeof(int) * wordsSize);
    int i,j;
    int max = 0;
    int t;
    
    for (i=0; i<wordsSize; i++) {
        char *w = words[i];
        p[i] = 0;
        
        while (*w) {
            p[i] |= 1 << (*w - 'a');
            w++;
        }
    }
    
    for (i=0; i<wordsSize; i++) {
        for (j=i+1; j<wordsSize; j++) {
            if ((p[i] & p[j]) == 0 && max < (strlen(words[i]) * strlen(words[j]))){
                 max = strlen(words[i]) * strlen(words[j]);
            }
        }
        //printf("%08x ", p[i]);
    }
    return max;   
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

