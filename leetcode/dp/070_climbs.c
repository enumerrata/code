#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
int climbStairs(int n) {
	if (n == 2)
		return 2;
	if (n == 1)
		return 1;
	
	return climbStairs(n-1) + climbStairs(n-2);
    
}
*/

int climbStairs(int n) {
    int a=1,b=2;
    int t,i;
    
    if (n < 3)
        return n;
    
    for (i=2; i<n; i++) {
        t=a+b;
        a=b;
        b=t;
    }
    
    return b;
}

int main(int argc, char *argv[])
{
	printf("> %d\n", climbStairs(4));

	return 0;
}

