#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
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
#endif

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int **a = obstacleGrid;
    int m = obstacleGridRowSize;
    int n = obstacleGridColSize;
    int i,j;
    
    for (i=0; i<m; i++)
        for (j=0; j<n; j++) {
            if (a[i][j] == 0) {
                if (!i || !j) {
                    if (!i && !j)
                        a[i][j] = -1;
                    else if (!i && a[i][j-1] <= 0) 
                        a[i][j] = -1;
                    else if (!j && a[i-1][j] <= 0)
                        a[i][j] = -1;
                    else
                        a[i][j] = 1;
                } else {
                    if (a[i-1][j] <= 0)
                        a[i][j] += a[i-1][j];
                    if (a[i][j-1] <= 0)
                        a[i][j] += a[i][j-1];
                }
            }
        }
    return a[m-1][n-1] <= 0? -a[m-1][n-1]: 0;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

