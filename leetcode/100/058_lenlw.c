#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int lengthOfLastWord(char* s) {
	char *p = s; 
	char *q = p;
	int in = 0;
	int len = 0;

	while (*p) {
		if (*p == ' ' && in) {
			in = 0;
		} else if (*p != ' ' && !in) {
			q = p;
			in = 1;
		}
		p++;
	}

	while (*q && *q != ' ') {
		len++;
		q++;
	}
		
	return len;
}

int main(int argc, char *argv[])
{
	//char *s = " Hello World a ";
	char *s = " a ";
	printf("> %d\n", lengthOfLastWord(s));

	return 0;
}

