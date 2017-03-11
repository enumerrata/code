#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void reverse(int *a, int i, int j)
{
    while (i < j)
        swap(&a[i++], &a[j--]);
}

void nextPermutation(int* nums, int numsSize) {
    int i,j;

    for (i = numsSize-2; i>=0; i--) {
        if (nums[i] < nums[i+1])
            break;
	}
	
   	if (i >= 0) {
		for (j=numsSize-1; j>=0; j--)
			if (nums[i] < nums[j])
				break;
				
		swap(&nums[i], &nums[j]);
	}
    
	reverse(nums, i+1, numsSize-1);
}


int main(int argc, char *argv[])
{
	int a[] = {3,2,1};

	nextPermutation(a, 3);
	printf("> %d %d %d\n", a[0], a[1], a[2]);

	return 0;
}

