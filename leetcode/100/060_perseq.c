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

int main(int argc, char *argv[])
{
	printf("> %s\n", getPermutation(3, 2));

	return 0;
}

