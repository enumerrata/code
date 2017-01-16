#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
	int i,j;

	for (i=0; i<obstacleGridRowSize; i++) {
		for (j=0; j<obstacleGridColSize; j++) {
		    if (obstacleGrid[i][j] == 1)
		        obstacleGrid[i][j] = -1;
		        
			if (i == 0) {
			    if (obstacleGrid[i][j] < 0)
			        obstacleGrid[i][j] = 0;
			    else if (j == 0)
				    obstacleGrid[i][j] = 1;
				else
				    obstacleGrid[i][j] = obstacleGrid[i][j-1];
			} else if (j == 0) {
			    if (obstacleGrid[i][j] < 0)
				    obstacleGrid[i][j] = 0;
				else
				    obstacleGrid[i][j] = obstacleGrid[i-1][j];
			} else {
			    if (obstacleGrid[i][j] < 0)
			        obstacleGrid[i][j] = 0;
				else
				    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
			}
		}
	}

    return obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

