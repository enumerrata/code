#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    // up and left
    int i,j;
    int cnt=0;
    int repeat=0;
    
    for (i=0; i<gridRowSize; i++)
        for (j=0; j<gridColSize; j++) {
            if (grid[i][j]) {
                cnt++;
                
                if (i>0 && grid[i-1][j]) 
                    repeat++;
                if (j>0 && grid[i][j-1])
                    repeat++;
            }
        }
    
    return cnt*4 - repeat*2;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

