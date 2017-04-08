#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

bool isMatch(char *s, char *p)
{
	if (*p == '\0')
		return *s == '\0';
	
	if (*(p+1) != '*') {
		if ((*p == *s) || *p == '.' && *s != '\0') {
			return isMatch(s+1, p+1);
		} else {
			return false;
		}
	}

	while ((*p == *s) || *p == '.' && *s != '\0') {
		if (isMatch(s, p+2))
			return true;
		s++;
	}

	return isMatch(s, p+2);
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

