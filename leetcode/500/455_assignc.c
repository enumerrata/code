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


int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int i=0,j=0;
    
    if (gSize<1 || sSize<1)
        return 0;
        
    qsort(g, gSize, sizeof(int), comparefn);
	qsort(s, sSize, sizeof(int), comparefn);
	
	while (i<gSize && j<sSize) {
	    if (g[i] <= s[j])
	        i++;
	    j++;
	}

    return i;
}

int main(int argc, char *argv[])
{
	int g[] = {1,2,3};
	int s[] = {3};

	printf("> %d\n", findContentChildren(g,3,s,1));

	return 0;
}

