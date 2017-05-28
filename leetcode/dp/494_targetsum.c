#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


#if 0
void dfs(int *nums, int d, int sum, int S, int *cnt, int numsSize)
{
    if (d == numsSize) {
        if (sum == S)
            *cnt += 1;
        return;
    }
    
    dfs(nums, d+1, sum-nums[d], S, cnt, numsSize);
    dfs(nums, d+1, sum+nums[d], S, cnt, numsSize);
}

int findTargetSumWays(int* nums, int numsSize, int S) {
    int cnt = 0;
    
    dfs(nums, 0, 0, S, &cnt, numsSize);
    
    return cnt;
}
#endif

int subsetSum(int *nums, int siz, int s) {
    int dp[s+1]; 
    int i,n;
    
    memset(dp, 0, sizeof(int)*(s+1));
    dp[0] = 1;
    for (n = 0; n < siz; n++)
        for (int i = s; i >= nums[n]; i--)
            dp[i] += dp[i - nums[n]]; 
    return dp[s];
} 

int findTargetSumWays(int* nums, int numsSize, int S) {
    int i,j;
    int sum=0;

    for (i=0; i<numsSize; i++) {
        sum += nums[i];
    }
    if (sum < S || (sum + S)%2)
        return 0;
    // subset sum = (sum+s)/2
    
    return subsetSum(nums, numsSize, (sum+S)/2);
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

