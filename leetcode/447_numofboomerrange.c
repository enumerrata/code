#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// should use map
int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize) {
    int len = 0;
    int i,j,k;
    int *prow;
    int d1,d2;
    int cnt=0;
    int cache[500][500];
    
    for (i=0; i<pointsRowSize; i++) {
        for (j=i+1; j<pointsRowSize; j++)  {
            cache[i][j] =  (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
            cache[i][j] += (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        }
    }
        
    for (i=0; i<pointsRowSize; i++) {

        for (j=0; j<pointsRowSize; j++)  {
            if (j == i) continue;
            for (k=0; k<pointsRowSize; k++) {
                if (k == i || k == j) continue;
                d1 = i < j ? cache[i][j] : cache[j][i];
                d2 = i < k ? cache[i][k] : cache[k][i];
                
                if (d1==d2)
                    cnt++;
				//printf("%d %d %d: %d %d \n", i,j ,k, d1, d2);
            }
        }
	}
    return cnt;
}

int main(int argc, char *argv[])
{
	int a[] = {0,0 };
	int b[] = {1,0 };
	int c[] = {2,0 };
	int *d[] = {a,b,c};

	printf("> %d \n", numberOfBoomerangs(d, 3, 2));

	return 0;
}

