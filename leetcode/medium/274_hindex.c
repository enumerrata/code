#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int hIndex(int* citations, int citationsSize) {
	int i,j;

	for (i=0; i<citationsSize-1; i++) {
		for (j=i+1; j<citationsSize; j++) {
			if (citations[j] > citations[i]) {
				int t;
				t = citations[j];
				citations[j] = citations[i];
				citations[i] = t;
			}
		}
	}

	for (i=0; i<citationsSize; i++) {
		if (i >= citations[i])
			break;
	}

   	return i; 
}

int main(int argc, char *argv[])
{
	int a[] = {3, 0, 6, 1, 5};
	printf("> %d\n", hIndex(a, 5));

	return 0;
}

