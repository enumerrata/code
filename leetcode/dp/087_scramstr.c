#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

//dp[i][j][len] = 
// 	dp[i][j][k] && dp[i+k][j+k][len-k] || 
//  dp[i][j+len-k][k] && dp[i+k][j][len-k])

bool isScramble(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (len1 != len2)
		return false;

	bool dp[len1][len1][len1+1];
	int i,j,len,k;

	memset(dp, 0, sizeof(dp));
	for (i=0; i<len1; i++)
		for (j=0; j<len1; j++) {
			dp[i][j][1] = s1[i] == s2[j];
		}

	for(len = 2; len <= len1; len++)
		for(i = 0; i < len1 - len + 1; i++)
			for(j = 0; j < len1 - len + 1; j++)
				for(k = 1; k < len; k++)
					dp[i][j][len] = dp[i][j][len] || 
						dp[i][j][k] && dp[i + k][j + k][len - k] || 
						dp[i][j + len - k][k] && dp[i + k][j][len - k];

	return dp[0][0][len1];
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

