#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row;
    int l=0;
    int h=matrixRowSize-1;
    int m;
    
    while (l <= h) {
        m = l + (h-l)/2;
        
        if (matrix[m][0] < target) 
            l = m + 1;
        else if (matrix[m][0] > target)
            h = m - 1;
        else
            return true;
    }
    
	printf(">> %d %d\n", h, l);
    if (h < 0 || l > matrixRowSize)
        return false;
    int mm = h;
    l = 0; h = matrixColSize - 1;
    
	printf(">> %d %d\n", h, l);
    while (l <= h) {
        m = l + (h-l)/2;
        
        if (matrix[mm][m] < target) 
            l = m + 1;
        else if (matrix[mm][m] > target)
            h = m - 1;
        else
            return true;
    }
    return false;   
}

int main(int argc, char *argv[])
{
	int a[] = {1,3};
	int *p[] = {a};
	printf("> %d\n", searchMatrix(p, 1, 2,3));

	return 0;
}

