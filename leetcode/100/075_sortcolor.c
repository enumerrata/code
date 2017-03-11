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

void sortColors(int* nums, int numsSize) {
    int s=0, e=numsSize-1, cur=0;
	int i;
    
    while (cur <= e && s < e) {
		while (s < numsSize && nums[s] == 0) {
			s++;
			if (cur < s)
				cur = s;
		}
		while (e >= 0 && nums[e] == 2)
			e--;

		if (s >= numsSize || e < 0 || cur > e)
			break;
#if 1
		for (i=0; i<numsSize; i++) {
			printf("%d ", nums[i]);
		}
		printf("\n");
		printf(">> %d %d %d\n", s, cur, e);
#endif

		if (nums[cur] == 1)
			cur++;
		else if (nums[cur] == 2) {
			swap(&nums[e], &nums[cur]);
			e--;
		} else if (nums[cur] == 0){
			swap(&nums[s], &nums[cur]);
			s++;
		}
    }
}

int main(int argc, char *argv[])
{
	//int t[] = {1,2,2,2,2,0,0,0,1,1};
	int t[] = {0,2,1};
	//int t[] = {0,1};
	//int t[] = {1,0};

	sortColors(t, sizeof(t)/sizeof(int));
	printf("> \n");

	int i;
	for (i=0; i<sizeof(t)/sizeof(int); i++) {
		printf("%d \n", t[i]);
	}

	return 0;
}

