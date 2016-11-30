#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **p = malloc(sizeof(char *) * (n+1));
    int i;
    
   
    for (i=1; i<=n; i++) {
        if (!(i%3) && !(i%5))
            p[i] = "FizzBuzz";
        else if (!(i%3))
            p[i] = "Fizz";
        else if (!(i%5))
            p[i] = "Buzz";
        else {
            p[i] = malloc(11);
            sprintf(p[i], "%d", i);
        }
    }
    *returnSize = n;
    return &p[1];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

