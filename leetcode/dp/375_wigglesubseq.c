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
int wiggleMaxLength(int* nums, int numsSize) {
    
    if (numsSize < 1)
        return numsSize;
    
	int dp[2][numsSize];
	int i,j;

	dp[0][0] = 1;
	dp[1][0] = 1;

	for (i=1; i<numsSize; i++) {
		for (j=1; j<numsSize; j++) {
			if (nums[j] > nums[j-1]) {
				dp[0][j] = dp[1][j-1] + 1;
				dp[1][j] = dp[1][j-1];
			} else if (nums[j] < nums[j-1]) {
				dp[1][j] = dp[0][j-1] + 1;
				dp[0][j] = dp[0][j-1];
			} else {
				dp[0][j] = dp[0][j-1];
				dp[1][j] = dp[1][j-1];
			}
			
		}
	}
#if 0
	for (i=0; i<2; i++) {
		for (j=0; j<numsSize; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
#endif
   	return  max(dp[0][numsSize-1], dp[1][numsSize-1]);
}

int main(int argc, char *argv[])
{
	//int a[] = {1,17,5,10,13,15,10,5,16,8};

	int a[] = {0,0};

	printf("> %d \n", wiggleMaxLength(a, sizeof(a)/sizeof(a[0])));

	return 0;
}

