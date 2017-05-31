#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
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
#endif

int numTrees(int n) {
    int p[n+1];
    int i,j,sum;
    
    p[0] = 1;
    p[1] = 1;
    
    for (i=2; i<n+1; i++) {
        sum = 0;
        for (j=0; j<i; j++) {
            sum += p[j] * p[i-j-1];
        }
        p[i] = sum;
    }
    return p[n];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

