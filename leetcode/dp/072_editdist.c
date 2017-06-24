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

int minDistance(char* word1, char* word2) {
	int m = strlen(word1);
	int n = strlen(word2);
	int dp[m+1][n+1];
	int i,j;

	memset(dp, 0, sizeof(dp));

	for (i=1; i<m+1; i++)
		dp[i][0] = i;

	for (i=1; i<n+1; i++)
		dp[0][i] = i;
	
	for (i = 1; i < m+1; i++) {
		for (j = 1; j < n+1; j++) {
			if (word1[i - 1] == word2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1];
			else 
				dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i][j-1]+1, dp[i-1][j] + 1));
		}
	}

	return dp[m][n];
}

int main(int argc, char *argv[])
{
	printf("> %d\n", minDistance("park", "spake"));

	return 0;
}

