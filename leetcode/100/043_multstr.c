#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char* multiply(char* num1, char* num2) {
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len = len1 + len2;

	int *p = malloc(sizeof(int) * len);
	memset(p, 0, sizeof(int)* len);

	int i,j;

	for (i=0; i<len2; i++)
		for (j=0; j<len1; j++) {
			p[len-1-i-j] += (num2[len2-i-1] - '0') * (num1[len1-1-j] - '0');
		}

   	//printf("%d %d %d\n", p[len-1], p[len-2], p[len-3]); 
	char *pp = malloc(sizeof(char) * (len+2));

	for (i=len-1; i>0; i--) {
		p[i-1] += p[i] / 10;
		pp[i] = (p[i] % 10) + '0';
	}
	pp[0] = (p[0] % 10) + '0';
	pp[len] = '\0';
	i=0;

	while (i <len  && (pp[i] == '0' || pp[i] == 0))
		i++;
	
	if (i == len) {
		pp[0] = '0';
		pp[1] = '\0';
		return pp;
	}
	
	return pp+i;
}

int main(int argc, char *argv[])
{
	char *num1="0";
	char *num2="0";

	char *p;

	p = multiply(num1, num2);
	printf("> %s\n", p);

	return 0;
}

