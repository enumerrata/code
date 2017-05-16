#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

bool isMatch(char* s, char* p) {
    const char* star=NULL;  
    const char* ss=s;   
    
    while (*s){  
        if ((*p=='?')||(*p==*s)) {
            s++;p++;continue;
        }  
        
        if (*p=='*') {
            star=p++; ss=s;continue;
        } 
        
        if (star) { 
            p = star+1; s=++ss;continue;
        }
        
        return false;  
    }  
    
    while (*p=='*') { 
        p++;
    }  
    
    return !*p; 
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

