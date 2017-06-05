#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int min(int a, int b)
{
    return a>b?b:a;
}

int numSquares(int n) {
    int i=0,j;
    int *dp;
    int min1;
    
    dp = calloc((n+1), sizeof(int));
    
    while (i*i <= n) {
        dp[i*i] = 1;
        i++;
    }
    
    for (i=2; i<n+1; i++) {
        min1 = INT_MAX;
        if (!dp[i]) {
            for (j=1; j<=i/2; j++) {
                min1 = min(min1, dp[j]+dp[i-j]);
            }
            dp[i] = min1;
        }
    }
    return dp[n];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

