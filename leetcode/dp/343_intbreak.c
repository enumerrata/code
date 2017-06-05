#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
int integerBreak(int n) {
    int prod = 1;
    
    if (n==2) return 1;
    if (n==3) return 2;
    
    while (n > 4) {
        prod *= 3;
        n -= 3;
    }
    
    return prod * n;
}
#endif

int max(int a, int b)
{
    return a>b?a:b;
}

int integerBreak(int n) {
    int dp[n+1];
    int i,j,t;
    int max1=1;
    
    if (n<=1)
        return 0;
    dp[0] = 0;
    dp[1] = 0;
    
    for (i=2; i<n+1; i++) {
        max1 = 0;
        for (j=1; j<=i/2; j++) {
            t = max(j,dp[j]) * max(i-j,dp[i-j]);
            max1 = t>max1?t:max1;
        } 
        dp[i] = max1;
    }
    
    return dp[n];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

