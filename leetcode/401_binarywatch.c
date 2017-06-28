#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


#if 0

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

void gen(int num, int cur, int siz, int *a, int max, int *p, int *len, int alen) {
	int i,j,t;

	if (num > max)
		return ;

	if (siz == 0) {
		p[(*len)++] = num;
		return;
	}

	for (i=cur; i<alen; i++) {
		num += a[i];
		gen(num, i+1, siz-1, a, max, p, len, alen);
		num -= a[i];
	}
		
}

char *tostr(int h, int m)
{
	char *p;
	p = malloc(sizeof(char) * 6);
	sprintf(p, "%d:%02d", h, m);
	return p;
}

char** readBinaryWatch(int num, int* returnSize) {
    char **p;
    int *siz = returnSize;
    int i,j,k;
	int a[10] = {1,2,4,8,16,32};
	int len1=0,len2=0;
	int a1[60];
	int a2[60];

    *siz = 0;
    p = malloc(sizeof(char *) * 1000);
    
    if (!num) {
        p[(*siz)++] = strdup("0:00");
        return p;
    }
    
	for (i=0; i<num+1; i++) {
		len1 = len2 = 0;
		gen(0, 0, i, a, 11, a1, &len1, 4);
		gen(0, 0, num-i, a, 59, a2, &len2, 6);

		for (j=0; j<len1; j++) {
			for (k=0; k<len2; k++) {
				p[(*siz)++] = tostr(a1[j], a2[k]);
			}
		}
	}
	return p;
}
#endif

int main(int argc, char *argv[])
{
	int ret,i;
	char **p;

	p = readBinaryWatch(2, &ret);

	for (i=0; i<ret; i++)
		printf("%s\n", p[i]);

	return 0;
}

