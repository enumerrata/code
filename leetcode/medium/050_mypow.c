#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

double myPow(double x, int n) {
    double sum=1;
	double a = x;
    int i;
	int sign=1;

	if (n < 0) {
		n = -n;
		sign = -1;
	}
    
    for (i = 0; i < 32; i++) {
        if (n & (1<<i)) {
			sum *= a;
		}
		//printf(">>> %f %f\n", sum, a);
		a *= a;
    }
	if (sign < 0)
		return 1/sum;
    return sum;
}

int main(int argc, char *argv[])
{
	printf("> %f\n", myPow(8.8802, -2));

	return 0;
}

