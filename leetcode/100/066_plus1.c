#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    int c = 0;
    int *p = malloc(sizeof(int) * (digitsSize + 1));

    digits[digitsSize-1] += 1;

    for (i= digitsSize - 1; i >= 0; i--) {
		p[i] = digits[i] + c;
		if (p[i] >= 10) {
			p[i] -= 10;
			c = 1;
		} else {
			c = 0;
		}
    }
	
	if (!c) {
		*returnSize = digitsSize;
	} else {
		*returnSize = digitsSize + 1;
    	for (i=0; i < digitsSize; i++) {
			p[i+1] = p[i];
		}
		p[0] = 1;
	}

    return p;
}

int main(int argc, char *argv[])
{
	int a[5] = {9,9,9,9,9};
	int r;
	int *p;
	int i;

	p = plusOne(a, 5, &r);

	for (i = 0; i < r; i++) {
		printf("%d ", p[i]);
	}

	printf("> \n");

	return 0;
}

