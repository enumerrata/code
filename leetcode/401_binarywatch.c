#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


#if 1

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

#else

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void gen(int num, int cur, int siz, int *a) {
	int i,j,t;

	if (siz == 0) {
		for (i=0; i<10; i++)
			printf("%d ", a[i]);
		printf("\n", a[i]);
		return;
	}

	for (i=cur; i<10; i++) {
		a[i] = 1;
		gen(num, i+1, siz-1, a);
		a[i] = 0;
	}
		
}

char** readBinaryWatch(int num, int* returnSize) {
    char **p;
    int *siz = returnSize;
    int i;
	int a[10] = {0};

    *siz = 0;
    p = malloc(sizeof(char *) * 1000);
    
    if (!num) {
        p[(*siz)++] = strdup("0:00");
        return p;
    }
    
	gen(10, 0, num, a);
    
}
#endif

int main(int argc, char *argv[])
{
	int ret,i;
	char **p;

	p = readBinaryWatch(2, &ret);

	for (i=0; i<ret; i++)
		printf("> %s\n", p[i]);

	return 0;
}

