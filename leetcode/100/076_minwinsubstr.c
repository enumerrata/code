#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

char* minWindow(char* s, char* t) {

	int srcHash[255] = {0};
	int ls = strlen(s);
	int lt = strlen(t);
	int i;
	int start = 0;
	int destHash[255]={0};
	int found = 0;
	int begin = -1, end = strlen(s), minLength = strlen(s);


	for(i = 0; i < lt; i++){
		srcHash[t[i]]++;
	}

	for(start = i = 0; i < ls; i++){
		destHash[s[i]]++;
		if(destHash[s[i]] <= srcHash[s[i]]) found++;

		if(found == lt){
			while(start < i && destHash[s[start]] > srcHash[s[start]]){
				destHash[s[start]]--;
				start++;
			}
			if(i - start < minLength){
				minLength = i - start;
				begin = start;
				end = i;
			}
			destHash[s[start]]--;
			found--;
			start++;
		}
	}
	s[end+1] = '\0';
	printf("b %d\n", begin);
	return begin == -1 ? "" : &s[begin];
}

int main(int argc, char *argv[])
{
	char a[] ="a";
	char b[] ="b";

	printf("> %s\n", minWindow(a, b));

	return 0;
}

