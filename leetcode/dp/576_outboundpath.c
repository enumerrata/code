#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int findPaths(int m, int n, int N, int i, int j) {
    long long dp[N+1][m][n];
    int x,y,k;
    
    memset(dp, 0, sizeof(dp));
    for (k=1; k<N+1; k++) {
        for (x=0; x<m; x++) {
            for (y=0; y<n; y++) {
                long long v1 = (x == 0) ? 1 : dp[k - 1][x - 1][y];
                long long v2 = (x == m - 1) ? 1 : dp[k - 1][x + 1][y];
                long long v3 = (y == 0) ? 1 : dp[k - 1][x][y - 1];
                long long v4 = (y == n - 1) ? 1 : dp[k - 1][x][y + 1];
                dp[k][x][y] = (v1 + v2 + v3 + v4) % 1000000007;
            }
        }
    }
    return dp[N][i][j];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

