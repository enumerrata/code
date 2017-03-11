#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool isValid(char* s) {
	char *p = s;
	char *st;
	int len=0;

	st = malloc(strlen(s));
	while (*p) {
		if (*p == '(' || *p == '[' || *p == '{') {
			st[len++] = *p;
		} else if (*p == ')') {
			if (--len < 0 || st[len] != '(')
				return false;
		} else if (*p == ']') {
			if (--len < 0 || st[len] != '[')
				return false;
		} else if (*p == '}') {
			if (--len < 0 || st[len] != '{')
				return false;
		}
		p++;
	}
	if (len)
		return false;

	return true;
}

int main(int argc, char *argv[])
{
	printf("%d\n", isValid("({ })"));

	return 0;
}

