#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
int isv(char a) {
    return a <= '9' && a >= '1';
}

int isv2(char a, char b) 
{
    return a == '1' || a == '2' && b <= '6';    
}

int numDecodings(char* s) {
    int w1 = 1;
    int w2 = 1;
    int i;
    int len = strlen(s);
    int w = 0;
    
    if (s[0] == '0' || !len)
        return 0;
    
    for (i=1; i<len; i++) {
        w = 0;
        if (!isv(s[i]) && !isv2(s[i-1], s[i]))
            return 0;
        
        if (isv(s[i]))
            w += w1;
            
        if (isv2(s[i-1], s[i]))
            w += w2;
        
        w2 = w1;
        w1 = w;
            
    }

    return w1;
}
#endif
int numDecodings(char* s) {
    int cnt = 1;
    int len = strlen(s);
    int dp[len+1];
    int i;

    if (len < 1)
        return 0;
    
    if (s[0] == '0')
        return 0;

    dp[0] = 1;
    dp[1] = 1;

    for (i=2; i<len+1; i++) {
        dp[i] = 0;

        if (s[i-1]>'0')
            dp[i] += dp[i-1];

        if (s[i-2] == '1' || s[i-2] == '2' && s[i-1]<='6') {
            dp[i] += dp[i-2];
        }
    }
    //printf("%d %d %d\n", dp[0], dp[1], dp[2]);
    return dp[len];

}
int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

