#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
int uniquePaths(int m, int n) {
	int sum = 0;

	if (n<1 || m<1)
		return 0;

   	if (n == 1 || m == 1) 
		return 1;

   	if (n == 2 && m == 2) 
		return 2;
	
	printf("%d %d\n", m, n);

	if (n >= 2) {
		sum += uniquePaths(m, n-1);
	} 

	if (m >= 2) {
		sum += uniquePaths(m-1, n);
	} 
	return sum;
}
#endif

int uniquePaths(int m, int n) {
	int *p = malloc(sizeof(int) * m * n);
	int i,j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			if (i==0 || j==0) {
				p[i*m + j] = 1;
			} else {
				p[i*m + j] = p[(i-1)*m + j] + p[i*m + j -1];
			}
		}
	}
#if 0
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			printf("%d ", p[i*m + j]);
		}
		printf("\n");
	}
#endif

	return p[n*m-1];
}

int main(int argc, char *argv[])
{
	printf("> %d\n", uniquePaths(23,12));

	return 0;
}

