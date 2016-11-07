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
	int a=2;
	int b=1;
	int i;
	int s=0;

	if (n == 2)
		return 2;
	if (n == 1)
		return 1;
	
	for (i=0; i<n-2; i++) {
		s = a + b;	
		b = a;
		a = s;
	}
	return s;
}

int main(int argc, char *argv[])
{
	printf("> %d\n", climbStairs(4));

	return 0;
}

