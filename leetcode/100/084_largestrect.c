#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int largestRectangleArea(int* heights, int heightsSize) 
{
    int s[heightsSize + 1];
	int top = 0;
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    while (i < heightsSize)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (top == 0 || heights[s[top-1]] <= heights[i]) {

            s[top++] = i; i++;
		}
 
        // If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = s[top-1];  // store the top index
            top--;  // pop the top
 
            // Calculate the area with heights[tp] stack as smallest bar
            area_with_top = heights[tp] * (top == 0 ? i : i - s[top-1] - 1);
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (top)
    {
        tp = s[top - 1];
		top--;
        area_with_top = heights[tp] * (top==0 ? i : i - s[top -1] - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}

int main(int argc, char *argv[])
{
	int a[]={2,1,5,6,2,3};
	printf("> %d\n", largestRectangleArea(a, 6));

	return 0;
}

