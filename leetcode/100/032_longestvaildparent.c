#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int max(int a, int b)
{
	return a>b?a:b;
}

int longestValidParentheses(char* s) 
{
	int start = -1;  
	int maxlen = 0;  
	int stack[10000];
	int top = 0;
	int i;

	for (i=0; i<strlen(s); i++) {  
		if(s[i] =='(') {  
			stack[top++] = i;
		} else {  
			if(top) {  
				top--;
				if (!top) {  
					maxlen = max(i - start , maxlen);  
				} else {  
					maxlen = max(i - stack[top-1] , maxlen);  
				}  
			} else {  
				start = i;  
			}  
		}  
	}  

	return maxlen;  
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

