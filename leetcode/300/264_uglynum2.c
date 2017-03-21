#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "tree.h"

int min(int a, int b)
{
	return a>b?b:a;
}

int nthUglyNumber(int n) {
	int *p;
	int n2=0,n3=0,n5=0;
	int num = 1;
	int k = 0;

	p = malloc(sizeof(int) * (n+1));
	p[k++] = 1;

	while (k < n) {
		p[k] = min(p[n2]*2, min(p[n3]*3, p[n5]*5));

		//printf(">>> %d %d %d %d\n", num, p[n2]*2, p[n3]*3, p[n5]*5);

		if (p[k] == p[n2]*2)
			n2++;
		if (p[k] == p[n3]*3)
			n3++;
		if (p[k] == p[n5]*5)
			n5++;
		k++;
	}
   	return p[k-1]; 
}

int main(int argc, char *argv[])
{
	printf("> %d\n", nthUglyNumber(8));

	return 0;
}

