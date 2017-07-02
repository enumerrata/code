#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#if 0
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void add(char **p, char *s, int *siz, int len1)
{
	int len = strlen(s);
	int i=0;

	for (i=*siz*len; i>=0; i--) {
		strcpy(p[i], p[i/len]);
		p[i][len1] = s[i%len];
		//printf(">> %s \n", p[i]);
	}

	*siz *= len;
}

char** letterCombinations(char* digits, int* returnSize) {
	int len = strlen(digits);
	char **p;
	int i;
	char *map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",  "wxyz" };
	int siz = 1;

	if (!len) return NULL;

	p = malloc(sizeof(char *) * 5000);

	for (i=0; i<5000; i++) {
		p[i] = malloc(len+1);
		memset(p[i], 0, len+1);
	}

	for (i=0; i<len; i++) {
		add(p, map[digits[i] - '0'], &siz, i);
	}

	*returnSize = siz;
   	return p; 
}
#else

void gen(char *digits, char **map, int *l, int len,  int cur, char *stack, int top, char **p, int *siz)
{
	int i,j,c;

	if (len == top) {
		//printf("-- %d  %s\n", len, stack);
		p[(*siz)++] = strdup(stack);

		return;
	}

	for (i=cur; i<len; i++) {
		c = digits[i] - '0';
		//printf(">> %d \n", c);
		for (j=0; j<l[c]; j++) {
			stack[top++] = map[c][j];
			//printf("%c \n", stack[top-1] );
			gen(digits, map, l, len, i+1, stack, top, p, siz);
			top--;
		}
	}
	
}

char** letterCombinations(char* digits, int* returnSize) {
	char **p;
	char *map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",  "wxyz" };
	int l[]={0,0,3,3,3,3,3,4,3,4};
	int len=strlen(digits);
	char stack[len+1];

	*returnSize = 0;
    if (!len)
        return NULL;
	stack[len] = '\0';
	p = malloc(sizeof(char *) * 1000);
	gen(digits, map, l, len, 0, stack, 0, p, returnSize);

	return p;
}
#endif

int main(int argc, char *argv[])
{
	int siz;
	int i;
	char **p;

	p = letterCombinations("999", &siz);
	printf("> %d\n", siz);

	for (i=0; i<siz; i++)
		printf("%s\n", p[i]);

	return 0;
}

