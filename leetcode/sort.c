#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>



void shuffle(int *a, int n)
{
	int t,p1,p2;
	int cnt = 1000;
	time_t tt;
	
	time(&tt);
	srandom(tt);
	
	while (cnt--) {
		p1 = random() % n;
		p2 = random() % n;
		t = a[p1];
		a[p1] = a[p2];
		a[p2] = t;
	}
}

void pr(int *a, int n)
{
	int i;

	for (i=0; i<n; i++) {
		printf("%02d ", a[i]);
	}
	printf("\n");
}

void swap(char *a, char *b)
{
	int t;
	
	t = *a;
	*a = *b;
	*b = t;
}

void selectsort_reverse(int *a, int n)
{
	int i,j;

	for (i=1; i<n; i++) {
		int t = a[i];
		for (j=i; j>=1 && a[j-1] < t; j--) {
				a[j] = a[j-1];
		}
		a[j] = t;
	}

}
void selectsort(int *a, int n)
{
	int i,j;

	for (i=1; i<n; i++) {
		int t = a[i];
		for (j=i; j>=1 && a[j-1] > t; j--) {
				a[j] = a[j-1];
		}
		a[j] = t;
	}

}

int main(int argc, char *argv[])
{
	int a[100];
	int i;

	for (i=0; i<100; i++) {
		a[i] = i;
	}

	shuffle(a, 100);
	selectsort(a, 100);

	for (i=0; i<100; i++) {
		if (a[i] != i) {
			pr(a, 100);
			break;
		}
	}

	return 0;
}

