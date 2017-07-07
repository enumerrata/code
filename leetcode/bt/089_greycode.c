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
//https://en.wikipedia.org/wiki/Gray_code
int* grayCode(int n, int* returnSize) {
    int siz=pow(2, n);
    int *p = malloc(sizeof(int) * siz);
    int i;
    
    *returnSize = siz;
    
    for (i=0; i<siz; i++)
        p[i] = i ^ (i>>1); 
    
    return p;
}
#else
void gen(int *num, int n, int *p, int *siz)
{
	//printf("--%d \n",n);
	if (n == 0) {
		p[(*siz)++] = *num;
		return;
	}

	gen(num, n - 1, p, siz);
	*num ^= (1 << n - 1);
	gen(num, n - 1, p, siz);
}

int* grayCode(int n, int* returnSize) {
	int num = 0;
	int *p = 0;

	p = malloc(sizeof(int) * 10000);
	*returnSize = 0;

	gen(&num, n, p, returnSize);
    return p;
}
#endif

int main(int argc, char *argv[])
{
	int *p;
	int siz;

	p = grayCode(1, &siz);
	printf("> \n");

	return 0;
}

