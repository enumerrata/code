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

int findMaxForm(char** strs, int strsSize, int m, int n) {
    int i,j,k;
    int ones, zeros;
    int dp[m+1][n+1];
    
    memset(dp, 0, sizeof(int)*(m+1)*(n+1));
    
    for (i=0; i<strsSize; i++) {
        ones=0; zeros=0;
        for (j=0; strs[i][j]; j++) {
            if (strs[i][j]=='0')
                zeros++;
            else
                ones++;
        }
        
        for (j=m; j>=zeros; j--)
            for (k=n; k>=ones; k--) {
                dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones]+1);
            }
    }
    return dp[m][n];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

