#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


void removek(char *s, int id)
{
    int len = strlen(s);
    int i;
    
    for (i=id; i<len-1; i++) {
        s[i] = s[i+1];
    }
    s[len-1] = '\0';
}



char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    int t = k;
    int i=0;
    
    while (num[i] && k>0) {
        if (num[i+1] < num[i]) {
            removek(num, i);
            k--;
            if (i>0)
                i--;
        } else {
            i++;
        }
    }
    num[len-t] = '\0';
    while (*num == '0')
        num++;
    return *num==0?"0":num;
    
}
int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

