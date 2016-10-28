#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPalindrome(int x) {
	long long y = 0;
	int xx = x;

	if (x < 0) {
        return false;
	}

	while (x) {
		y = y*10 + x % 10;
		x /= 10;
	}
	if (xx == y)
		return true;

	return false;
}


int main(int argc, char *argv[])
{

	printf("%d\n", isPalindrome(-0));

	return 0;
}

