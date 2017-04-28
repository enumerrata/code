#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

struct elem {
    int times;
    char c;
};

int comparefn( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) 
		 return 0;
     else if ( int_a < int_b ) 
		 return 1;
     else 
		 return -1;
}


char* frequencySort(char* s) {
    struct elem map[128]={0};
    int i,j;
    
    for (i=0; i<26; i++) {
        map['A'+i].c = 'A'+i;
        map['a'+i].c = 'a'+i;
    }
    
    for (i='0'; i<='9'; i++) {
        map[i].c = i;
    }
    map[' '].c = ' ';
    map['.'].c = '.';
    map['\\'].c = '\\';
    map['\''].c = '\'';
    map[','].c = ',';
    map['\"'].c = '\"';

    for (i=0; s[i]; i++) {
        map[s[i]].times += 1;
    }
    
	qsort(map, 128, sizeof(struct elem), comparefn);

	//for (i=0; i<128; i++) 
	//	printf("%d  %c %d\n",i, map[i].c, map[i].times);
	
	i=0; j=0;
	while (map[i].times) {
	    memset(&s[j], map[i].c, map[i].times);
	    //printf("%d >%c<\n", map[i].times, map[i].c);
	    j += map[i].times;
	    i++;
	}

    return s;
}

int main(int argc, char *argv[])
{
	char a[]="Mymommaalwayssaid,\"Lifewaslikeaboxofchocolates.Youneverknowwhatyou'regonnaget.";
	printf("> %s\n", frequencySort(a));

	return 0;
}

