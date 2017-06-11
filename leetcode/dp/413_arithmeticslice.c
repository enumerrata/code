#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int numberOfArithmeticSlices(int* A, int ASize) {
    int count = 0;
    int addend = 0;

    for (int i = 2; i < ASize; i++)
        if (A[i - 1] - A[i] == A[i - 2] - A[i - 1])
            count += ++addend;
        else 
            addend = 0;

    return count;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

