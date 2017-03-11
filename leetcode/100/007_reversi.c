#include <stdio.h>

int reverse(int x) {
	long t=0;
	int sign = 1;

	if (x < 0) {
		x = -x;	
		sign = -1;
	}

	while (x) {
		t = t * 10 + x % 10;
		x /= 10;
	}

	t *= sign;
    
	printf("%ld", t);
}

int main(int argc, char *argv[])
{
	reverse(-2147483648);

	return 0;
}



