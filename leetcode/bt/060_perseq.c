#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int removeone(char *p, int nth, int len)
{
	int t = p[nth];
	int i;

	for (i=nth; i<len-1; i++) {
		p[i] = p[i+1];
		//printf ("%02d ", p[i]);
	}
	//printf ("\n");

	return t;
}

char* getPermutation(int n, int k) {
	int nn = n;
	char *p = malloc(sizeof(char) * (n + 1));
	char *remain = malloc(sizeof(char) * (n));
	int i,t;
	int total=1;
	int cur=0;

	memset(p, 0, n+1);

	for (i=0; i<n; i++) {
		remain[i] = i+1;
		total *= (i+1);
	}

	while (nn > 1) {
		total /= nn;
		cur = (k-1)/total; 
		//printf("cur %d\n", cur);

		t = removeone(remain, cur, nn);
		//printf("t  %d\n", t);
		k = k - cur * total;
		//printf("k  %d\n", k);
		p[n-nn] = t + '0';
		nn--;
	}
	t = removeone(remain, 0, 1);
	p[n-1] = t + '0';
    
    return p;
}
#if 0
int cmp(const void *p1, const void *p2)
{
	return *(char *)p1 > *(char *)p2;
}
void swap(char *a, char *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void gen(char *p, int nsiz, int cur, int k, int *cnt, char **q)
{
	int i=0;
	char *t;

	if (cur == nsiz) {
		*cnt += 1;
		//printf("%d %s \n", *cnt, p);
		if (*cnt == k) {
			*q = strdup(p);
		}
		return;
	}

	for (i=cur; i<nsiz; i++) {
		swap(&p[cur], &p[i]);
		t = strdup(p);
		if (cur+1  < nsiz) {
			qsort(t+i, nsiz-i, sizeof(char), cmp);
		}
		gen(t, nsiz, cur+1, k, cnt, q);
	}
}

char* getPermutation(int n, int k) {
	char *p,*q=NULL;
	int i;
	int cnt=0;

	p = calloc(sizeof(char),n+1);
	for (i=0; i<n; i++) {
		p[i] = i + '1';
	}
	gen(p, n, 0, k, &cnt, &q);

	return q;
}
#endif

int main(int argc, char *argv[])
{
	printf("> %s\n", getPermutation(3, 5));

	return 0;
}

