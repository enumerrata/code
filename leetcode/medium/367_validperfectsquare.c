#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isPerfectSquare(int num) {
    long long  l=1, h=num,m;
    
    while (l <= h) {
        long long t;
        m = l + (h-l)/2;
        t = m*m;
        if (t < num) {
            l = m + 1;
        } else if (t > num) {
            h = m - 1;
        } else {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

