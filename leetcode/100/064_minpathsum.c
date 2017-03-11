#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int min;
    int i,j;
    
    for (i=0; i<gridRowSize; i++) {
        for (j=0; j<gridColSize; j++) {
            if (i==0) {
                if (j > 0)
                    grid[i][j] += grid[i][j-1]; 
            } else if (j == 0) {
                if (i > 0)
                    grid[i][j] += grid[i-1][j]; 
            } else {
                grid[i][j] += grid[i][j-1] > grid[i-1][j] ? grid[i-1][j] : grid[i][j-1];
            }
        }
    }
    
    return grid[gridRowSize-1][gridColSize-1];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

