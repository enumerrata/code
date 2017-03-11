#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>



int majorityElement(int* nums, int numsSize) {
	int i;
	int c = 0;
	int count = 0;

	for (i=0; i<numsSize; i++) {
		if (count == 0) {
			c = nums[i];
			count = 1;
		} else {
			if (nums[i] == c)
				count++;
			else
				count--;
		}
	}
	return c;
}

int main(int argc, char *argv[])
{
	int a[10] = {2,4,4,4,9};
	int i;
	int ret;

	ret = majorityElement(a, 5);

	for (i=0; i<5; i++)
		printf("%d ", a[i]);

	printf("> %d \n", ret);

	return 0;
}
