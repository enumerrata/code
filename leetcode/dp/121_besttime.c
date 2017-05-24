#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int maxProfit(int* prices, int pricesSize) {
    int i,j;
    int max = 0;
    int min = prices[0];
    
    if (pricesSize < 2)
        return 0;
        
    for (i=0; i<pricesSize; i++) {
        if (prices[i] - min > max)
            max = prices[i] - min;
        
        if (prices[i] < min)
            min = prices[i];
        
    }
    return max;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

