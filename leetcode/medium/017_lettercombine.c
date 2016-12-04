#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>


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

