#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int ndigit(int n, int pos)
{
	int a[11] = {0};
	int len = 0;
    
	while (n) {
		a[len++] = n % 10;
		n /= 10;
	}

	while (pos--) {
		len--;
	}

	return a[--len];
}

int findNthDigit(int n) {
	int bits = 0;
	long long base = 0;
	long long sum = 0;
	long long snext = 0;
	int num;
	int pos;

	while (n > snext) {
		sum = snext;
		bits++;
		if (!base)
			base = 1;
		else
			base *= 10;
		snext = snext + base * 9 * bits;
	}
	//printf("bits %d  base %d sum %d \n", bits, base, sum);

	num = (n - sum - 1)/bits + base;
	pos = (n - sum - 1) % bits;

	//printf("%d %d\n", num, pos);

	return ndigit(num, pos);
}

int main(int argc, char *argv[])
{
#if 0
	printf("> %d\n", findNthDigit(8));
	printf("> %d\n", findNthDigit(9));
	printf("> %d\n", findNthDigit(10));
	printf("> %d\n", findNthDigit(11));

	//printf("> %d\n", findNthDigit(100));
	//printf("> %d\n", findNthDigit(190));
#endif

	printf("> %d\n", findNthDigit(1000000000));
	return 0;
}

