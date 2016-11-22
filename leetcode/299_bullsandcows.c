#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char* getHint(char* secret, char* guess) {
    int bull = 0;
    int cow = 0;
    int map1[10] = {0};
    int map2[10] = {0};
    int i;
    
    while (*secret) { 
        if (*secret == *guess) {
            bull++;
        } else {
            map1[*secret - '0']++;
            map2[*guess - '0']++;
        }
        secret++;
        guess++;
    }
    
    for (i=0; i<10; i++) { 
        if (map1[i] && map2[i])
            cow += map1[i] > map2[i] ? map2[i] : map1[i];
    }
    char *p = malloc(sizeof(char) * 100);
    sprintf(p, "%dA%dB", bull, cow);
    
    return p;
}


int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

