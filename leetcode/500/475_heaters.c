#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"
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


int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    int max = 0;
    int i,j=0;
    
    qsort(houses, housesSize, sizeof(int), comparefn);
    qsort(heaters, heatersSize, sizeof(int), comparefn);

    for (i=0; i<housesSize; i++) {
        while (j<heatersSize - 1 && abs(heaters[j] - houses[i]) >= abs(heaters[j+1] - houses[i]))
            j++;
        max = max > abs(heaters[j] - houses[i]) ? max : abs(heaters[j] - houses[i]);
    }
    return max;
}


int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

