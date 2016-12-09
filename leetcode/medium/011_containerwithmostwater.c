#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int maxArea1(int* height, int heightSize) {
    int i,j;
    int max=0;
    
    for (i=0; i<heightSize-1; i++)
        for (j=i+1; j<heightSize; j++) {
            int min = height[i] > height[j] ? height[j] : height[i];
            if ((j-i) * min > max)
                max = (j-i) * min;
        }
    return max;
}

int maxArea(int* height, int heightSize) {
    int i=0,j=heightSize-1;
    int max=0;
    
    while (i < j) {
        if (height[i] < height[j]) {
            int t = (j-i) * height[i];
            if (t > max)
                max = t;
            i++;
        } else {
            int t = (j-i) * height[j];
            if (t > max)                 
                max = t;
            j--;
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

