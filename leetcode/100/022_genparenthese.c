#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void printpare(char *p, int n, int open, int close, char **pp, int *siz)
{
	//printf("%d %d %d\n", n, open, close);

	if (open == 0 && close == 0) {
		p[n] = '\0';
		pp[*siz] = strdup(p);
		*siz += 1;
		return ;
	}

	if (open < close) {
		p[n] = ')';
		printpare(p, n+1, open, close-1, pp, siz);
	}

	if (open > 0) {
		p[n] = '(';
		printpare(p, n+1, open-1, close, pp, siz);
	}

}

char** generateParenthesis(int n, int* returnSize) {
	char *p = malloc(sizeof(char) * (2 *n +1));
	char **pp = malloc(sizeof(char *) * 2000);
	int siz = 0;

	printpare(p, 0, n, n, pp, &siz);

	*returnSize = siz;
    
	return pp;
}

int main(int argc, char *argv[])
{
	int siz;
	int i;
	char **p;

	p = generateParenthesis(8, &siz);

	for (i=0; i<siz; i++) {
		printf("%s\n", p[i]);
	}

	printf("> %d\n", siz);

	return 0;
}

