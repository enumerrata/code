#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
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
#else
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void gen(char *stack, int top, int open, int close, char **p, int *siz)
{
	if (!open && !close) {
		//printf("%s\n", stack);
		p[(*siz)++] = strdup(stack);
		return ;
	}

	if (open) {
		stack[top++] = '(';
		gen(stack, top, open-1, close, p, siz);
		top--;
	}

	if (close > open) {
		stack[top++] = ')';
		gen(stack, top, open, close-1, p, siz);
		top--;
	}
}

char** generateParenthesis(int n, int* returnSize) {
	char **p;
	char stack[n*2+1];

	
	stack[2*n] = '\0';
	*returnSize = 0;
	p = malloc(sizeof(char *) * 2000);
	gen(stack, 0, n, n, p, returnSize);

	return p;
}
#endif

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

