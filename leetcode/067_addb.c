#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// 110 111
char* addBinary(char* a, char* b) {
	char *p;
	int lena = strlen(a);
	int lenb = strlen(b);
	int len = 0;
	int c = 0;

	if (!lenb || !lena)
		return NULL;

	len = lena > lenb ? lena + 2 : lenb + 2;

	p = malloc(len);
	p[--len] = '\0';
	lena--; lenb--;
	
	while (lena >= 0 || lenb >= 0) {
		if (lena >= 0 && lenb >= 0) {
			p[--len] = (a[lena]-'0' + b[lenb] - '0' + c) % 2  + '0';
			c = (a[lena]-'0' + b[lenb] - '0' + c) / 2;
			lena--;
			lenb--;
		} else if (lena >= 0) {
			p[--len] = (a[lena]-'0' + c) % 2 + '0';
			c = (a[lena]-'0' + c)/2;
			lena--;
		} else {
			p[--len] = (b[lenb]-'0' + c) % 2 + '0';
			c = (b[lenb]-'0' + c)/2;
			lenb--;
		}
	}
	if (c)
		p[--len] = c + '0';

	return p+len;
    
}

int main(int argc, char *argv[])
{
	char *p = addBinary("111", "1");
	printf("> %d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4]);
	printf("> %s\n", p);

	return 0;
}

