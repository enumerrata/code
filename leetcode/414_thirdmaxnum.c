#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
int thirdMax(int* nums, int numsSize) {
    int max[3] = {0};
    int i = 0;
    int len = 1;
    
    max[0] = nums[0];
    
    for (i=0; i<numsSize; i++) {
		printf("<< %d %d %d %d \n", max[0], max[1], max[2], len);

        if (len < 3 && nums[i] < max[len-1]) {
            max[len++] = nums[i];
			printf("append\n");
            continue;
        }

		if (nums[i] == max[0])
			continue;
        
		if (nums[i] == max[1] && len > 1)
			continue;

        if (nums[i] > max[0]) {
            max[2] = max[1];
            max[1] = max[0];
            max[0] = nums[i];
            if (len < 3) len++;
			printf("1\n");
        } else if (nums[i] > max[1] && len > 1) {
            max[2] = max[1];
            max[1] = nums[i];
            if (len < 3) len++;
			printf("2\n");
        }  else if (nums[i] > max[2] && len > 2) {
            max[2] = nums[i];
            if (len < 3) len++;
			printf("3\n");
        }  
		printf(">> %d %d %d %d \n", max[0], max[1], max[2], len);

    }
    return len ==3 ? max[len-1] : max[0];
}
int main(int argc, char *argv[])
{
	int a[3] = { 1, 2 ,2 };

	printf("> %d\n", thirdMax(a, 3));

	return 0;
}

