#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool ispalin(char *s, int start, int end) {

	end--;
    while (end > start) {
		if (s[start] != s[end])
			return false;
        end--;
        start++;
    }
    return true;
}

char *dupstr(char *s, int start, int end)
{
	char *p = NULL; 

	if (end > start) {
		p = malloc(end-start);
		memcpy(p, s+start, end-start);
		p[end-start] = '\0';
	}

	return p;
}

void help(char *s, int len, int start, char ***p, int **csiz, int *siz, char **stack, int top) 
{
	int i,j;

	if (start == len) {
		p[*siz] = malloc(sizeof(char *) * top);
		memcpy(p[*siz], stack, top*(sizeof(char*)));
		(*csiz)[*siz] = top;
		//for (j=0; j<top; j++)
		//	printf("%s ",stack[j]);
		//printf("\n");
		*siz += 1;
		return ;
	}

	for (i=start; i<len; i++) {
		if (ispalin(s, start, i+1)) {
			stack[top++] = dupstr(s, start, i+1);
			help(s, len, i+1, p, csiz, siz, stack, top);
			top--;
		}
	}
}

char*** partition(char* s, int** columnSizes, int* returnSize) {
	char ***p = malloc(sizeof(char *) * 1000);
	int len = strlen(s);
	char **stack;
	int top = 0;

	if (!s)
		return NULL;

	stack = malloc(sizeof(char *) * 1000); 
	*columnSizes = malloc(sizeof(int) * 1000);
	(*columnSizes)[0] =  0;
	*returnSize = 0;

	help(s, len, 0, p, columnSizes, returnSize, stack, top);
	return p;
}

int main(int argc, char *argv[])
{
    char s[] = "aab";
    int *csiz;
    int siz;
    int i, j;

    char ***p;

    p = partition(s, &csiz, &siz);

    for (i = 0; i < siz; i++) {
        for (j = 0; j < csiz[i]; j++) {
            printf("%s ", p[i][j]);
        }
        printf("\n");
    }

	return 0;
}

