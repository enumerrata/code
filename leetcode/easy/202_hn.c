#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int cal(int n)
{
    int sum = 0;
    int t;
    
    while (n) {
        t = n % 10;
        n /= 10;
        sum += t * t;    
    }
    return sum;
}

bool isin(int *p, int len, int n)
{
    int i;
    
    for (i=0; i<len; i++) {
        if (p[i] == n)
            return true;
    }
    return false;
}

bool isHappy(int n) {
    int l[100];
    int len = 0;
    int v;
    
    while (1) {
        v = cal(n);
		printf("%d ", v);
        
        if (v == 1)
            return true;
            
        if (isin(l, len, v))
            return false;
        
        l[len++] = n;
		n = v;
    }
}

int main(int argc, char *argv[])
{
	printf("> %d\n", isHappy(23));

	return 0;
}

