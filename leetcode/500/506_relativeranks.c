#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

struct elem {
	int rank;
	int id;
};



int cmpi_r( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
	 printf(">> %d %d \n", int_a, int_b);

     if ( int_a == int_b ) 
		 return 0;
     else if ( int_a > int_b ) 
		 return -1;
     else 
		 return 1;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* nums, int numsSize, int* returnSize) {
	struct elem *p;
	int i;
	char **pp;
	int id;

	p = malloc(sizeof(struct elem) * numsSize);
	pp = calloc(numsSize, sizeof(char *));
	*returnSize = numsSize;

	for (i=0; i<numsSize; i++) {
		p[i].rank = nums[i];
		p[i].id = i;
	}
   	qsort(p, numsSize, sizeof(struct elem), cmpi_r); 

	for (i=0; i<numsSize; i++) {
		id = p[i].id;
#if 1
		if (i == 0)
			pp[id] = strdup("Gold Medal");
		else if (i == 1)
			pp[id] = strdup("Silver Medal");
		else if (i == 2)
			pp[id] = strdup("Bronze Medal");
		else {
			pp[id] = malloc(20);
			sprintf(pp[id], "%d", i+1);
		}
#endif
		printf("%d %d %s\n", id, p[i].rank, pp[id]);
	}
	return pp;
}
// "Gold Medal", "Silver Medal", "Bronze Medal"
int main(int argc, char *argv[])
{
	int a[] = {123123,11921,1,0,123};
	char **p;
	int siz;
	int i;

 	p = findRelativeRanks(a, 5, &siz);
	for (i=0; i<siz; i++) {
		printf("%s\n", p[i]);
	}
	printf("\n");

	return 0;
}

