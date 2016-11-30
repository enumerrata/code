#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int** generate(int numRows, int** columnSizes) {
    int i,j;
    
    int **p = malloc(sizeof(int *) * numRows);
    int *pcol = malloc(sizeof(int) * numRows);
    int *t;
    
    t = malloc(sizeof(int));
    *t = 1;
    p[0] = t;
    pcol[0] = 1;
    
    for (i=1; i<numRows; i++) {
        int *l = malloc(sizeof(int) * (i + 1));
        l[0] = 1;
        
        for (j=1; j<i; j++) {
            l[j] = *(p[i-1] + j - 1) + *(p[i-1] + j);
        }
        
        l[i] = 1;
        p[i] = l;
        pcol[i] = i+1;
    }
    *columnSizes = pcol;
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

