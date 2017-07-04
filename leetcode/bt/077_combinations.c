#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void comb(int *l, int *d, int s, int e, int id, int k, int **out, int *len) 
{
	int i;

	if (id == k) {
		memcpy(out[*len], d, sizeof(int)*k);
		*len += 1;
		//printf("%d %d\n", d[0], d[1]);
		return ;
	}

	for (i=s; i<=e-(k-id-1); i++) {
		d[id] = l[i];
		comb(l, d, i+1, e, id+1, k, out, len);
	}

}

int** combine(int n, int k, int** columnSizes, int* returnSize) {
	int i,j;
	long siz=n;
	int *p = malloc(sizeof(int) * n); 
	int *d = malloc(sizeof(int) * k); 
	int **out;
	int len = 0;

	for (i=1; i<k; i++) 
		siz *= (n-i);
	for (i=2; i<=k; i++)
		siz /= i;

	*returnSize = siz;
	*columnSizes = malloc(sizeof(int) * siz);
	out = malloc(sizeof(int *) * siz);

	for (i=0; i<siz; i++) {

		(*columnSizes)[i] = k; 
		out[i] = malloc(sizeof(int)*k);
	}

	for (i=0; i<n; i++)
		p[i] = i+1;
	
	comb(p, d, 0, n-1, 0, k, out, &len);
	
   	return out; 
}
#else
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void gen(int start, int end, int len, int *stack, int top, int **p, int *csiz, int *siz)
{
	int i;
	if (len==0) {
		p[*siz] = malloc(sizeof(int) * top);
		memcpy(p[*siz], stack, top*sizeof(int));
		csiz[*siz] = top;
		*siz += 1;
		return;
	}

	for (i=start; i<=end; i++) {
		stack[top++] = i;
		gen(i+1, end, len-1, stack, top, p, csiz, siz);
		top--;
	}

}

int** combine(int n, int k, int** columnSizes, int* returnSize) {
	int **p = malloc(sizeof(int*) * 10000);
	int stack[k+1];


	*returnSize = 0;
	*columnSizes = malloc(sizeof(int) * 10000);
	gen(1, n, k, stack, 0, p, *columnSizes, returnSize);
    
	return p;
}
#endif

int main(int argc, char *argv[])
{
	int **pp;
	int *p;
	int ret;
	int i,j;
	int k=1;

	pp = combine(1, k, &p, &ret);
	for (i=0; i<ret; i++) {
		for (j=0; j<k; j++)
			printf("%d ", pp[i][j]);
		printf("\n");
	}
	printf("> \n");

	return 0;
}

