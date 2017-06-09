#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int max(int a, int b)
{
	return a>b?a:b;
}

int longestPalindromeSubseq(char* s) {
	int len=strlen(s);
	int **p;
	int i,j;

	p = malloc(sizeof(int *) * (len+1));
	for (i=0; i<len+1; i++) {
		p[i] = malloc(sizeof(int) *(len+1));
		for (j=0; j<len+1; j++) {
			if (i == j)
				p[i][j] = 1;
			else
				p[i][j] = 0;
		}
	}
	for (i=len-1; i>=0; i--)
		for (j=i+1; j<len; j++) {
			if (s[i] == s[j]) {
				p[i][j] = p[i+1][j-1] + 2;
			} else {
				p[i][j] = max(p[i+1][j], p[i][j-1]);
			}
		}
#if 0
	for (i=0; i<len+1; i++) {
		for (j=0; j<len+1; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
#endif

   	return p[0][len-1]; 
}

int main(int argc, char *argv[])
{
	printf("> %d\n", longestPalindromeSubseq("bbbcb"));

	return 0;
}

