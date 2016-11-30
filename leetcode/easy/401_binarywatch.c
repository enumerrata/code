#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool check(int n, int bits)
{
    int cnt=0;
    int i=0;
    
    for (i=0; i<10; i++) {
        if (n & (1<<i))
            cnt++;
    }
    
    return cnt == bits;
}

char** readBinaryWatch(int num, int* returnSize) {
    int i;
    char **p;
    char *pa;
    int cnt=0;
    
    p = malloc(sizeof(char *) * 1000);
    pa = malloc(sizeof(char) * 6 * 1000);
    
    for (i=0; i<=(1<<10)-1; i++) {
        if (check(i, num)) {
			if ((i>>6) < 12 && (i & 0x3f) < 60) {
            	p[cnt++] = pa;
				sprintf(pa, "%d:%02d", i>>6, i & 0x3f);
				//printf(pa);
				pa += 6;
			}
        }
    }
    *returnSize = cnt;
    return p;
}

int main(int argc, char *argv[])
{
	int ret;

	readBinaryWatch(2, &ret);

	printf("> %d\n", ret);

	return 0;
}

