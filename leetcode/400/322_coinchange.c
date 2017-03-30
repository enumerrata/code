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

int coinChange(int* coins, int coinsSize, int amount) {
	int *dp;
	int i,j,k;

	dp = malloc(sizeof(int) * (amount+1));
	dp[0] = 0;
	for (i = 1; i <= amount; i++) {  
        dp[i] = 0x7fffffff;  
        for (j = 0; j < coinsSize; j++)  {

            if (i >= coins[j] && dp[i - coins[j]] != 0x7fffffff)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);  


		}
#if 0
		for (k = 1; k <= amount; k++) {  
			printf("%d ", dp[k]);
		}
		printf("\n");
#endif
    }  
    return dp[amount] == 0x7fffffff ? -1 : dp[amount];  
}
int main(int argc, char *argv[])
{
	int a[] = {1,2,5};

	printf("> %d\n", coinChange(a, 3, 11));

	return 0;
}

