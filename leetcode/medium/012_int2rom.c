#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//I 1
//V 5
//X 10
//L 50
//C 100
//D 500
//M 1,000

char* intToRoman(int num) {
    char *p[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int v[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	int i = 0;
	char *r = malloc(sizeof(char) * 100);
	char *q = r;

	while (num) {
		if (num >= v[i]) {
			strcpy(q, p[i]);
			q +=  strlen(p[i]);
			num -= v[i];
		} else {
			
			i++;
		}
	}

	return r;
}

int main(int argc, char *argv[])
{
	printf("> %s\n", intToRoman(11));

	return 0;
}

