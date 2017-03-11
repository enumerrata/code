#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int maxProfit(int* prices, int pricesSize) {
	int i;
	int sum=0;

	for (i=0; i<pricesSize-1; i++) {
		if (prices[i+1] > prices[i])
			sum += prices[i+1] - prices[i];
	}
   	return sum; 
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

