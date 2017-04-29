#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


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
int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

