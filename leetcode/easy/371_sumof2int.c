#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int getSum(int a, int b) {
    int i;
    int c=0;
    int sum=0;
    
    for (i=0; i<32; i++) {
        int abit = (a & (1<<i)) >> i;
        int bbit = (b & (1<<i)) >> i;
        
        if (c) {
            if (!abit && !bbit) {
                sum |= 1 << i;
                c = 0;
            } else if (abit && !bbit || !abit && bbit) {
                c = 1;
            } else {
                sum |= 1 << i;
                c = 1;
            }
            
        } else {
            if (!abit && !bbit) {
                c = 0;
            } else if (abit && !bbit || !abit && bbit) {
                sum |= 1 << i;
                c = 0;
            } else {
                c = 1;
            }  
        }
    }
    
    return sum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

