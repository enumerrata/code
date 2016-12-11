#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int divide_timeout(int dividend, int divisor) {
    long long n=0;
    long long dd = dividend;
    long long d = divisor;
    
    if (dd > 0 && d > 0) {
        while (dd >= d){
            dd -= d;
            n++;
        } 
    } else if (dd > 0 && d < 0) {
        d = -d;
        while (dd >= d){
            dd -= d;
            n++;
        }
        n = -n;
    } else if (dd < 0 && d > 0) {
        dd = -dd;
        while (dd >= d){
            dd -= d;
            n++;
        }
        n = -n;
    } else if (dd < 0 && d < 0) {
        dd = -dd;
        d = -d;
        while (dd >= d){
            dd -= d;
            n++;
        }
    }

	if ((n > 2147483647) || (n<-2147483648))
		return 2147483647;
    
    return n;
}


int divide(int dividend, int divisor) {

    if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
	
	int sign = (divisor > 0) ^ (dividend > 0) ? -1 : 1; 
	unsigned int dd = dividend > 0 ? dividend : -dividend;
	unsigned int d = divisor > 0 ? divisor: -divisor;
	
	int digi = 1;

	while ((d << digi) < dd)
		digi++;
	printf("%d\n", digi);

	long long num = 0;
	while (digi >= 0) {
		printf("%d\n", num);
		if (dd >= (d << digi)) {
			dd -= (d << digi);
			num |= 1 << digi;
		}
		digi--;
	}

	return num*sign;
}

int main(int argc, char *argv[])
{

	printf("> %d\n", divide(-1, 1));

	return 0;
}

