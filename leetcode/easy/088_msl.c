#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int* nums1, int m, int* nums2, int n) {
	int i1=0, i2=0, k=0;
	int *p;

    if (!n)
        return;
        
    p = malloc(sizeof(int) * m);
	memcpy(p, nums1, sizeof(int) * m);
	
	while (i1<m && i2<n) {
		if (p[i1] < nums2[i2]) {
			nums1[k++] = p[i1++];	
		} else {
			nums1[k++] = nums2[i2++];	
		}
	}

	while (i1<m)
		nums1[k++] = p[i1++];	

	while (i2<n)
		nums1[k++] = nums2[i2++];	

	free(p);
}

int main(int argc, char *argv[])
{
	int a[8] = {1,2,5,0};
	int b[3] = {5};
	int i;

	merge(a, 3, b, 0);

	for (i=0; i<5; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

