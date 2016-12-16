#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int mySqrt(int x) {
    int l = 1, h = x;

    while (l <= h) {
        int m = l + (h - l) / 2;
        if (m == x / m) {
            return m;
        } else if (m < x / m) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return h;
}

int main(int argc, char *argv[])
{
	printf("> %d\n", mySqrt(6));

	return 0;
}

