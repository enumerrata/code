#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int *p = malloc(sizeof(int) * triangleRowSize);
    int min = triangle[0][0];
    int i,j;
    
    memset(p, 0, sizeof(int) * triangleRowSize);
    for (i=1; i<triangleRowSize; i++) {
        for (j=0; j<=i; j++) {
            if (j==0)
                triangle[i][j] += triangle[i-1][j];
            else if (j==i)
                triangle[i][j] += triangle[i-1][j-1];
            else
                triangle[i][j] += triangle[i-1][j] > triangle[i-1][j-1]? triangle[i-1][j-1]: triangle[i-1][j];
        }
        
    }
    min = triangle[triangleRowSize-1][0];
    for (i=0; i<triangleRowSize; i++) {
        if (min > triangle[triangleRowSize-1][i])
            min = triangle[triangleRowSize-1][i];
    }
    return min;
}
#endif
int min(int a, int b)
{
    return a>b?b:a;
}
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int i,j;
    int **p = triangle;
    
    for (i=triangleRowSize-2; i>=0; i--) {
        for (j=0; j<triangleColSizes[i]; j++) {
            p[i][j] += min(p[i+1][j], p[i+1][j+1]);
        }
    }
    return p[0][0];
}
int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

