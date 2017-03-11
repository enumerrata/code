#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int searchleft(int* nums, int numsSize, int target) {
	int l=0;
	int h=numsSize-1;
	int m;

	while (l <= h) {
		m = (l + h)/2;
		if (nums[m] < target) {
			l = m + 1;	
		} else {
			h = m - 1;
		}
	}
   
   	return l; 
}

int searchright(int* nums, int numsSize, int target) {
	int l=0;
	int h=numsSize-1;
	int m;

	while (l <= h) {
		m = (l + h)/2;
		if (nums[m] <= target) {
			l = m + 1;	
		} else {
			h = m - 1;
		}
	}
   
   	return h; 
}



int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int *p = malloc(sizeof(int) * 2);


	p[0] = searchleft(nums, numsSize, target);
	p[1] = searchright(nums, numsSize, target);
   
   	*returnSize = 2;

	if (p[0] > p[1]) {
        p[0] = -1;
        p[1] = -1;
	}
   
   	return p; 
}

int main(int argc, char *argv[])
{
	int a[] = {1,3,3,3,5,6};
	int siz;
	int *p;

	//printf("> %d\n", searchleft(a, 4, 1));
	//printf("> %d\n", searchright(a, 4, 1));
	p = searchRange(a, 1, 0, &siz);

	printf("%d %d\n", p[0], p[1]);


	return 0;
}

