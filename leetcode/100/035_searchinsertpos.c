#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int searchInsert(int* nums, int numsSize, int target) {
	int l=0;
	int h=numsSize-1;
	int m;

	while (l <= h) {
		m = (l + h)/2;
		if (nums[m] == target) {
			return m;
		} else if (nums[m] < target) {
			l = m + 1;	
		} else {
			h = m - 1;
		}
	}
   
   	return l; 
}

int main(int argc, char *argv[])
{
	int a[] = {1,3,5,6};

	printf("> %d\n", searchInsert(a, 4, 5));
	printf("> %d\n", searchInsert(a, 4, 2));
	printf("> %d\n", searchInsert(a, 4, 7));
	printf("> %d\n", searchInsert(a, 4, 0));

	return 0;
}

