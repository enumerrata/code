#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"


int evalRPN(char** tokens, int tokensSize) {
    int *stack;
    int top=0;
    int i,a,b;
    
    stack = malloc(sizeof(int) * 10000);
    
    for (i=0; i<tokensSize; i++) {
        if (tokens[i][0] == '+') {
            b = stack[--top];
            a = stack[--top];
            stack[top++] = a+b;
        } else if (tokens[i][0] == '-' && tokens[i][1] == '\0') {
            b = stack[--top];
            a = stack[--top];
            stack[top++] = a-b;
        } else if (tokens[i][0] == '*') {
            b = stack[--top];
            a = stack[--top];
            stack[top++] = a*b;
        } else if (tokens[i][0] == '/') {
            b = stack[--top];
            a = stack[--top];
            stack[top++] = a/b;
        } else {
            stack[top++] = atoi(tokens[i]);
        }
    }
    return stack[0];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

