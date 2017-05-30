#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
int countNumbersWithUniqueDigits(int n) {
    int i = 2;
    int sum = 10;
    int t = 9;
    int j = 9;
    
    if (!n)
        return 1;
    
    while (i<=n) {
        t = t * j;
        sum += t;
        j -= 1;
        i++;
    }
    
    return sum;  
}
#endif


/* 10 +9*9 +9*9*8 +9*9*8*7 */
int countNumbersWithUniqueDigits(int n) {
    int num = 9;
    int i;
    int sum = 10;
    
    if (n == 0)
        return 1;
    if (n == 1)
        return 10;

    for (i=2; i<=n; i++) {
        num = num * (10-i+1);
        sum += num;
    }
    
    return sum;
}
int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

