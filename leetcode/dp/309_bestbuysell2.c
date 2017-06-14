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

int maxProfit(int* prices, int pricesSize) {
    int s0=0;
    int s1=-prices[0];
    int s2=INT_MIN;
    int i,t1,t2;

    for (i=1; i<pricesSize; i++) {
        t1 = s0;
        s0 = max(s2, s0);
        s1 = max(s1, t1-prices[i]);
        s2 = s1 + prices[i]; 
    }    
    return max(s0, s2);
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

