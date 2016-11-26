#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int maxRotateFunction(int* A, int ASize) {
    int *p;
    int i,j;
    long long max;
    long long sum=0;
    
    if (ASize < 2)
        return 0;
    
    p = malloc(sizeof(int) * ASize * 2);
    
    memcpy(p, A, sizeof(int) * ASize);    
    memcpy(p+ASize, A, sizeof(int) * ASize);
    
    for (j=0; j<ASize; j++) {
        sum += p[ASize+j] * j;
    }
    max = sum;
    
    for (i=ASize-1; i>0; i--) {
        sum -= p[i]*(ASize-1);
        for (j=1; j<ASize; j++) {
            sum += p[i+j];
        }
        //printf("%d\n", sum);
        if (max < sum)
            max = sum;
    }

    return max;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

