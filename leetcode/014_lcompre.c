#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	char *p =  strs[0];
	int i,j;

	if (strsSize == 0)
		return "";

	for (i = 1; i < strsSize; i++) {
		j = 0;

		while (p[j] && strs[i][j] && p[j] == strs[i][j])
			j++;

		p[j] = 0;
	}

	return p;
}

int main(int argc, char *argv[])
{
	char a[] = "abcd";
	char b[] = "ab";
	char c[] = "abcdty";

	char *tests[3];


	tests[0] = a;
	tests[1] = b;
	tests[2] = c;

	printf("%s \n", longestCommonPrefix(tests, sizeof(tests)/sizeof(tests[0])));

	return 0;
}

