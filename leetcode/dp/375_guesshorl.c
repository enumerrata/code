#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


int max(int a, int b)
{
    return a>b?a:b;
}
int min(int a, int b)
{
    return a>b?b:a;
}
int getMoneyAmount(int n) {
    int a[n+1][n+1];
    int i,j,k;
    
    memset(a, 0, sizeof(a));
    
    for (j=2; j<=n; j++) {
        for (i=j-1; i>0; i--) {
            int gmin = INT_MAX;
            for (k=i+1; k<j; k++) {
                int lmax = k + max(a[i][k-1], a[k+1][j]);
                gmin = min(gmin, lmax);
            }
            a[i][j] = i+1==j?i:gmin;
			//printf("%02d %02d: %d\n", i, j, a[i][j]);
        }
    }
    return a[1][n];   
}

int main(int argc, char *argv[])
{
	printf("> %d\n", getMoneyAmount(10));

	return 0;
}

