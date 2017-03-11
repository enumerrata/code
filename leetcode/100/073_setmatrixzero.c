#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int c0 = 1;
    int r0 = 1;
    int i,j;
    
    for (i=0; i<matrixRowSize; i++) {
        for (j=0; j<matrixColSize; j++) {
            if (matrix[i][j] == 0) {
				if (i != 0 && j != 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				} else {
					if (i == 0) {
						r0 = 0;
					}
					if (j == 0) {
						c0 = 0;
					}
				}
            }
        }
    }
    
    for (i=1; i<matrixRowSize; i++) {
        for (j=1; j<matrixColSize; j++) {
			if (matrix[i][0]== 0  || matrix[0][j] == 0) {
				matrix[i][j] = 0;
				//printf(">> %d %d\n", i,j);
			}
        }
    }

	if (r0 == 0)
    	for (j=0; j<matrixColSize; j++)
			matrix[0][j] = 0;

	if (c0 == 0)
    	for (i=0; i<matrixRowSize; i++)
			matrix[i][0] = 0;

}

int main(int argc, char *argv[])
{
	int a[]= {0,0,0,5};
	int b[]= {4,3,1,4};
	int c[]= {0,1,1,4};
	int d[]= {1,2,1,3};
	int e[]= {0,0,1,1};

	int *p[] = {a,b,c,d,e};

	//[[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]

	setZeroes(p, 5, 4);
	printf("%d %d %d %d\n", p[1][0], p[1][1], p[1][2], p[1][3]);
	printf("> \n");

	return 0;
}

