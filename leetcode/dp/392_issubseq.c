#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
bool isSubsequence(char* s, char* t) {
    
    while (*s && *t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    
    return !*s;
}
#endif

/* LCS */
bool isSubsequence(char* s, char* t) {
    int m=strlen(s);
    int n=strlen(t);
    bool *dp;
    int i,j;
    int pre,tt;
    
    if (!m && n || !m && !n)
        return true;
    
    dp = calloc(n+1, sizeof(bool));
	dp[0] = s[0] == t[0];
    
	for (j=1; j<n; j++) {
		dp[j] = s[0] == t[j] ? true: dp[j-1];
	}

    for (i=1; i<m; i++) {
        pre = 0;
        for (j=1; j<n; j++) {
            tt = dp[j];
            if (s[i] == t[j]) {
                if (j==1)
                    dp[j] = dp[j-1];
                else
                    dp[j] = dp[j-1] | pre;

            } else  {
				if (j==1)
					dp[j] = 0;
				else
					dp[j] = dp[j-1];
			}

            pre = tt;
       
        }
		//printf("%d %d %d %d \n", dp[0], dp[1], dp[2], dp[3]);
    }
    
    return dp[n-1];
}

int main(int argc, char *argv[])
{
	printf("> %d\n", isSubsequence("axc", "ahbgdc"));

	return 0;
}

