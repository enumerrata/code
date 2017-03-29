#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

#define T_NUM 1
#define T_OP  2
#define T_PR  3

int getnext(char *s, int *pos, int *n)
{
	int num = 0;
	int j = 0;

	while (s[*pos] == ' ')
		(*pos)++;

	if (s[*pos] == 0) {
		return -1;
	} else if (s[*pos] == '-' || s[*pos] == '+' || s[*pos] == '*' || s[*pos] == '/') {
		*n = s[*pos];
		(*pos)++;
		return 2;
	} else if (s[*pos] == '(' || s[*pos] == ')') {
		*n = s[*pos];
		(*pos)++;
		return 3;
	} else if (s[*pos] >= '0' && s[*pos] <= '9') {
		while (s[*pos] >= '0' && s[*pos] <= '9') {
			num = num * 10 + s[*pos] - '0'; 
			(*pos)++;
		}
		*n = num;
		return 1;
	} else {
		return 4;
	}

	return -1;
}

int calculate(char* s) {
	int pos = 0;
	int type = 0;
	int value;
	int result = 0;
	int op = 0;
	int opst[1000];
	int numst[1000];
	int optop = 0;
	int numtop = 0;
   
	while ( (type = getnext(s, &pos, &value)) != -1) {
		
		if (type == T_OP) {
			if (value == '*' || value == '/') {
				if (value == '*') {
					getnext(s, &pos, &value);
					numst[numtop-1] *= value;
				} else {
					getnext(s, &pos, &value);
					numst[numtop-1] /= value;
				}
			} else if (optop){
				if (opst[optop-1] == '+') {
					numst[numtop-2] += numst[numtop -1];
					numtop--;
				} else {
					numst[numtop-2] -= numst[numtop -1];
					numtop--;
				}
				opst[optop-1] = value;
			} else {
				opst[optop++] = value;
			}
		} else if (type == T_NUM) {
				numst[numtop++] = value;
		} 

	}
	printf("%d %d %d %d\n", numtop, optop, numst[0], numst[1]);	

	while (optop) {
		if (opst[--optop] == '+') {
			numst[numtop-2] += numst[numtop -1];
		} else {
			numst[numtop-2] -= numst[numtop -1];
		}
	}

	return numst[0];
}

int main(int argc, char *argv[])
{
	printf("> %d\n", calculate("2+1*4"));

	return 0;
}

