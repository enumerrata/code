#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int search(int* nums, int numsSize, int target) {
	int l,h,m;

	l = 0; 
	h = numsSize - 1;

	while (l <= h) {
		m = l + (h - l)/2;

		if (nums[m] == target)
			return m;

		// right up 
		if(nums[m] < nums[l]){
			// in right
			if(target > nums[m] && target <= nums[h]){
				l = m + 1;
			} else {
				h = m - 1;
			} 
		// left up
		} else {
			// in left
			if(target >= nums[l] && target <= nums[m]){
				h = m - 1; 
			} else {
				l = m + 1;
			}
		}
	}
   	return -1; 
}

int main(int argc, char *argv[])
{
	int a[] = {4,5,6,7,0,1,2};

	printf("> %d\n", search(a, 7, 3));

	return 0;
}

