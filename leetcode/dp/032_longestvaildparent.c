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

#if 0
int longestValidParentheses(char* s) 
{
	int start = -1;  
	int maxlen = 0;  
	int stack[10000];
	int top = 0;
	int i;

	for (i=0; i<strlen(s); i++) {  
		if(s[i] =='(') {  
			stack[top++] = i;
		} else {  
			if(top) {  
				top--;
				if (!top) {  
					maxlen = max(i - start , maxlen);  
				} else {  
					maxlen = max(i - stack[top-1] , maxlen);  
				}  
			} else {  
				start = i;  
			}  
		}  
	}  

	return maxlen;  
}
#else
/*
The idea is go through the string and use DP to store the longest valid parentheses at that point.
take example "()(())"
i : [0,1,2,3,4,5]
s : [( ,) ,( ,( ,) ,) ]
DP:[0,2,0,0,2,6]

1, We count all the ‘(‘.
2, If we find a ‘)’ and ‘(‘ counter is not 0, we have at least a valid result size of 2. “()"
3, Check the the one before (i - 1). If DP[i - 1] is not 0 means we have something like this “(())” . This will have DP “0024"
4, We might have something before "(())”. Take "()(())” example, Check the i = 1 because this might be a consecutive valid string.
 */

int longestValidParentheses(char* s)  
{
	int len = strlen(s);
	if (!len)
	    return 0;
	    
	int dp[len]; 
	int i;
	int cnt=0;
	int max1 = 0;

	memset(dp, 0, sizeof(dp));

	for (i=0; i<len; i++) {
		if (s[i] == '(') {
			cnt++;
		} else if (cnt > 0) {
			dp[i] = dp[i-1] + 2;
			dp[i] += (i - dp[i]) > 0 ? dp[i-dp[i]]:0;
			max1 = max(dp[i], max1);
			cnt--;
		}
	}
	return max1;
}
#endif

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

