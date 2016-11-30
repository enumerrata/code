#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int countPrimes(int n) {
    int *p;
    int cnt = 1;
    int cur = 2;
    
    if (n <= 2)
        return 0;
    
    p = malloc((n+1) * sizeof(int));
    memset(p, 1, sizeof(int) * (n+1));
    
    while (cur < n) {
        int i;
        for (i=cur; i<n; i+=cur) {
            p[i] = 0;
        }
        while (!p[cur]) {
            cur++;
        }
            
        if (cur >= n)
            return cnt;
        cnt++;
    }
    
    return cnt;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

