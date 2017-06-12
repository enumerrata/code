#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

#if 0

        // count[i] is the maximum unique substring end with ith letter.
        // 0 - 'a', 1 - 'b', ..., 25 - 'z'.
        int[] count = new int[26];
        
        // store longest contiguous substring ends at current position.
        int maxLengthCur = 0; 

        for (int i = 0; i < p.length(); i++) {
            if (i > 0 && (p.charAt(i) - p.charAt(i - 1) == 1 || (p.charAt(i - 1) - p.charAt(i) == 25))) {
                maxLengthCur++;
            }
            else {
                maxLengthCur = 1;
            }
            
            int index = p.charAt(i) - 'a';
            count[index] = Math.max(count[index], maxLengthCur);
        }
        
        // Sum to get result
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += count[i];
        }
        return sum;
#endif
int max(int a, int b)
{
    return a>b?a:b;
}

int findSubstringInWraproundString(char* p) {
    int dp[26];
    int len=strlen(p);
    int i,t;
    int sum=0;
    int maxlen=0;
    
    memset(dp, 0, sizeof(dp));

    for (i=0; i<len; i++) {
		t = p[i] - 'a';
		if (i && (p[i]-p[i-1]==1 || p[i-1]-p[i]==25))
			maxlen++;
		else
			maxlen=1;
		dp[t] = max(dp[t], maxlen);
    }

    for (i=0; i<26; i++) {
		printf("%d ", dp[i]);
        sum += dp[i];
    }
    return sum;
}
int main(int argc, char *argv[])
{
	printf("\n> %d\n", findSubstringInWraproundString("adg"));

	return 0;
}

