#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int *p = malloc(sizeof(int) * 2);
	int i = 0, j = numbersSize-1;

	*returnSize = 0;

	while (i < j) {
		int sum;

		sum = numbers[i] + numbers[j];
		if (sum < target)
			i++;
		else if (sum > target)
			j--;
		else {
			p[0] = i+1;
			p[1] = j+1;
			break;
		}
	}
   
   	*returnSize = 2;
   	return p; 
}

int main(int argc, char *argv[])
{
	int a[] = {2, 7, 11, 15};
	int siz;
	int *p;


	p = twoSum(a, 4, 9, &siz);
	
	printf("> %d %d\n", p[0], p[1]);

	return 0;
}

