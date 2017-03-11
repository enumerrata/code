#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


struct elem {
	int sum;
	int a;
	int b;
};


int cmp(const void *p1, const void *p2)
{
	//printf("%p %p\n", (struct elem *)p2, (struct elem *)p2);
	return ((struct elem *)p1)->sum > ((struct elem *)p2)->sum;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int** columnSizes, int* returnSize) {
    int **p;
	struct elem *q;
    int i,j;
	int kk=0;
	
	if (!nums1Size || !nums2Size) {
	    *returnSize = 0;
	    return NULL;
	}
	
	p = malloc(sizeof(int *) * k);
    *columnSizes = malloc(sizeof(int) * k);
    q = malloc(sizeof(struct elem) * nums1Size * nums2Size);
    
    for (i=0; i<nums1Size; i++) {
		for (j=0; j<nums2Size; j++) {
			q[i*nums2Size+j].sum = nums1[i] + nums2[j];
			q[i*nums2Size+j].a = nums1[i];
			q[i*nums2Size+j].b = nums2[j];
		}
	}
	qsort(q, nums1Size*nums2Size, sizeof(struct elem), cmp);

	for (kk=0; kk<k; kk++) {
		if (kk >= nums1Size * nums2Size)
			break;
		//printf("%d %d %d \n", q[kk].sum, q[kk].a, q[kk].b);
		p[kk] = malloc(sizeof(int) * 2);
		p[kk][0] = q[kk].a;
		p[kk][1] = q[kk].b;
		(*columnSizes)[kk] = 2;
	}
    
    *returnSize = kk;
    return p;
}

int main(int argc, char *argv[])
{
	int a[] = {1,1,2};
	int b[] = {1,2,3};
	int **p;
	int *csiz;
	int ret;
	int i;
	int k = 2;
	// [[1,1],[1,1],[1,2],[1,2],[2,1],[1,3],[1,3],[2,2],[2,3],[1,3]]
	// [[1,1],[1,1],[2,1],[1,2],[1,2],[2,2],[1,3],[1,3],[2,3]]

	p = kSmallestPairs(a, 3, b, 3, k, &csiz, &ret);

	printf("%d\n", ret);
	for (i=0; i<ret; i++) {
		printf("%d %d\n", p[i][0], p[i][1]);
	}

	printf("> \n");

	return 0;
}

