#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

char* complexNumberMultiply(char* a, char* b) {
	int a1,a2,b1,b2;
	char *p;

	a1 = strtol(a, NULL, 10);
	p = strtok(a, "+");
	p = strtok(NULL, "+");
	a2 = strtol(p, NULL, 10);

	b1 = strtol(b, NULL, 10);
	p = strtok(b, "+");
	p = strtok(NULL, "+");
	b2 = strtol(p, NULL, 10);
	//printf("%d %d %d %d\n", a1, a2, b1, b2);

	p = malloc(sizeof(char) *100);
	sprintf(p, "%d+%di", a1*b1-a2*b2, a1*b2+a2*b1);

   	return p;
}

int main(int argc, char *argv[])
{
	char a[] = "1+2i";
	char b[] = "1+3i";
	printf("> %s\n", complexNumberMultiply(a, b));

	return 0;
}

