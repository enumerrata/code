#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


//https://en.wikipedia.org/wiki/3SUM

/*
 sort(S);
 for i=0 to n-3 do
    a = S[i];
    start = i+1;
    end = n-1;
    while (start < end) do
       b = S[start]
       c = S[end];
       if (a+b+c == 0) then
          output a, b, c;
          // Continue search for all triplet combinations summing to zero.
           end = end - 1
       else if (a+b+c > 0) then
          end = end - 1;
       else
          start = start + 1;
       end
    end
 end
*/
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comparefn( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) 
		 return 0;
     else if ( int_a < int_b ) 
		 return -1;
     else 
		 return 1;
}

void add(int **p, int *len, int a, int b, int c)
{
	int *pp;
	int i;

	if (*len) {
		for (i=0; i<*len; i++) {
			if (p[i][0] == a && p[i][1] == b && p[i][2] == c)
				return;
		}
	}
	pp = malloc(sizeof(int) * 3);
	pp[0] = a; pp[1] = b; pp[2] = c;
	p[*len] = pp;
	*len += 1;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
	int i;
	int **p = malloc(sizeof(int *) * 5000);
	int *siz = returnSize;

   	*siz = 0; 
	p[0] = NULL;
	qsort(nums, numsSize, sizeof(int), comparefn);

	for (i=0; i<numsSize-2; i++) {
		int a=nums[i];
		int start = i+1;
		int end = numsSize - 1;

		while (start < end) {
			int b = nums[start];
			int c = nums[end];

			if (a+b+c == 0) {
				end = end - 1;
				add(p, siz, a, b, c);
				
			} else if (a+b+c > 0) {
				end = end -1;
			} else {
				start = start+1;
			}
		}
	}
	return p;
}

int main(int argc, char *argv[])
{
	int **p;
	int siz;
	//int a[] = {-1, 0, 1, 2, -1, -4};
	int a[] = {0, 0, 0};

	threeSum(a, 3, &siz);
	printf("> %d\n", siz);

	return 0;
}

