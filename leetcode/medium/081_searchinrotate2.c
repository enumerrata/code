#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


bool search(int* nums, int numsSize, int target) {
	int l,h,m;

	l = 0; 
	h = numsSize - 1;

	while (l <= h) {
		m = l + (h - l)/2;

		if (nums[m] == target)
			return true;

		// right up 
		if(nums[m] < nums[l]){
			// in right
			if(target > nums[m] && target <= nums[h]){
				l = m + 1;
			} else {
				h = m - 1;
			} 
		// left up
		} else if (nums[m] > nums[l]){
			// in left
			if(target >= nums[l] && target <= nums[m]){
				h = m - 1; 
			} else {
				l = m + 1;
			}
		} else {
			l++;
		}
	}
   	return false; 
}

int main(int argc, char *argv[])
{
	int a[] = {3,1,1};
	printf("> %d\n", search(a, 3, 3));

	return 0;
}

