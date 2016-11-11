#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*

1
1 1
1 2 1
1 3 3 1

*/
int* getRow(int rowIndex, int* returnSize) {
	int *p = malloc(sizeof(int) * (rowIndex + 1));
	int i,j;

	p[0] = 1;

	for (i=1; i<rowIndex+1; i++) {
		p[i] = 1;
		for (j=i-1; j>=0; j--) {
			p[j] = p[j] + p[j-1];
		}
	}
   
   	*returnSize = rowIndex + 1;
   	return p; 
}

int main(int argc, char *argv[])
{
	int *p;
	int siz;
	int i;

	p = getRow(3, &siz);
	for (i=0; i<siz; i++)
		printf("%d ", p[i]);
	printf("> \n");

	return 0;
}

