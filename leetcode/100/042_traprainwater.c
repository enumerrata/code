#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int trap(int* height, int heightSize) {
    int max=-1, idx;
    int i;
    int sum=0, cmax;
    
    for (i=0; i<heightSize; i++) {
        if (max < height[i]) {
            max = height[i];
            idx = i;
        }
    }
    cmax = height[0];
    for (i=0; i<idx; i++) {
        if (height[i] > cmax) {
            cmax = height[i];
        } else {
            sum += cmax -height[i];
        }
        
    }
    cmax=height[heightSize-1];
    for (i=heightSize-1; i>idx; i--) {
        if (height[i] > cmax) {
            cmax = height[i];
        } else {
            sum += cmax -height[i];
        }
        
    }
    return sum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

