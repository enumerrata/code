#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char **l = malloc(sizeof(char *) * numsSize);
    char *p;
    int len = 0, i;
    int b = 0;
    int e = nums[0];

	if (!numsSize)
		return NULL;
    
    for (i=0; i<numsSize + 1; i++) {
        if (i == numsSize || nums[i] != e) {
            l[len] = malloc(32);
			//printf("%d %d\n", nums[i], e);
            if (b != i-1)
                sprintf(l[len], "%d->%d", nums[b], nums[i-1]);
            else
                sprintf(l[len], "%d", nums[b]);
            b = i;
			e = nums[i] + 1;
            len++;
        } else {
            e++;
        }
    }

    *returnSize = len;
    return l;
}

int main(int argc, char *argv[])
{
	int a[] = {  0,8,9};
	int siz;
	char **p;

	p = summaryRanges(a, 3, &siz);
	printf("> %s\n", p[0]);
	printf("> %s\n", p[1]);

	return 0;
}

