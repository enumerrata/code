#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "tree.h"

#if 0
int min(int a, int b)
{
	return a>b?b:a;
}

int nthUglyNumber(int n) {
	int *p;
	int n2=0,n3=0,n5=0;
	int num = 1;
	int k = 0;

	p = malloc(sizeof(int) * (n+1));
	p[k++] = 1;

	while (k < n) {
		p[k] = min(p[n2]*2, min(p[n3]*3, p[n5]*5));

		//printf(">>> %d %d %d %d\n", num, p[n2]*2, p[n3]*3, p[n5]*5);

		if (p[k] == p[n2]*2)
			n2++;
		if (p[k] == p[n3]*3)
			n3++;
		if (p[k] == p[n5]*5)
			n5++;
		k++;
	}
   	return p[k-1]; 
}
#endif

int nthUglyNumber(int n) {
    int dp[n+1];
    int l2=0;
    int l3=0;
    int l5=0;
    int i;
    
    if (n == 1)
        return 1;
    dp[0] = 1;
    
    for (i=1; i<n; i++) {
        if (2*dp[l2] <= 3*dp[l3] && 2*dp[l2] <= 5*dp[l5]) {
            dp[i] = 2*dp[l2]; l2++;
            if (3*dp[l3] == dp[i])   l3++;
            if (5*dp[l5] == dp[i])   l5++;

        }else if (3*dp[l3]<=2*dp[l2] && 3*dp[l3] <= 5*dp[l5]) {
            dp[i] = 3*dp[l3]; l3++;
            if (2*dp[l2] == dp[i])   l2++;
            if (5*dp[l5] == dp[i])   l5++;
        }else if (5*dp[l5] <= 2*dp[l2] && 5*dp[l5] <= 3*dp[l3]) {
            dp[i] = 5*dp[l5]; l5++;
            if (2*dp[l2] == dp[i])   l2++;
            if (3*dp[l3] == dp[i])   l3++;
        }
        //printf("%d: %d %d %d %d\n", i, dp[i], l2, l3,l5);
    }
    return dp[n-1];
}
int main(int argc, char *argv[])
{
	printf("> %d\n", nthUglyNumber(8));

	return 0;
}

