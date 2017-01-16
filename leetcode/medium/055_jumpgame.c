#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


bool canJump(int* nums, int numsSize) {
    int i;
	int reach=nums[0];

	for (i=0; i<numsSize && i <= reach; i++) {
		reach = nums[i] + i > reach ? nums[i] + i : reach; 
	}
    
	printf("%d \n", reach);
   	return  reach >= numsSize - 1;
}

int main(int argc, char *argv[])
{
	//int a[] = {2,3,1,1,4};
	int a[] = {1,1,1,0};

	printf("> %d\n", canJump(a, 4));

	return 0;
}

