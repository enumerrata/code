#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int numTrees(int n) {
	int *p = calloc(n+1, sizeof(int));
	int i, j;

	p[0] = 1;
	p[1] = 1;

	for (i=2; i<n+1; i++) {
		for (j=0; j<i; j++) {
			p[i] += p[j]*p[i-j-1];
		}
	}
	return p[n];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

