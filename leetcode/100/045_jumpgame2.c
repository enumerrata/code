#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int max(int a, int b)
{
    return a>b?a:b;
}
int jump(int* nums, int numsSize) {
    int i,cnt=0;
    int cmax = 0;
    int crch = 0;

    for (i=0; i<numsSize; i++) {
        if (crch < i) {
            cnt++;
            crch = cmax;
        }
        cmax = max(cmax, i+nums[i]);
    }
    return cnt;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

