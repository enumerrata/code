#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void next(char *pre, char *next)
{
	char last = pre[0];
	int cnt = 0;

	do {
		if (*pre != last) {
			*next++ = cnt+'0';
			*next++ = last;
			last = *pre;
			cnt = 1;
		} else {
			cnt++;
		}

		pre++;
	} while (*pre);

	*next++ = cnt+'0';
	*next++ = last;
	*next = '\0';
}

char* countAndSay(int n) {
	char *p1 = malloc(10000);
	char *p2 = malloc(10000);
	char *t;

	p1[0] = '1';
	p1[1] = '\0';

	while (--n) {
		next(p1, p2);
		t = p1;
		p1 = p2;
		p2 = t;
	}

   	return p1;
}

int main(int argc, char *argv[])
{
	printf("%s \n", countAndSay(6));

	return 0;
}

