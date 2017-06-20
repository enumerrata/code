#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


int findIntegers(int num) 
{
	char str[33];
	int len = 0, i;

	while (num) {
		str[len++] = num%2 + '0';
		num /= 2;
	}
	str[len]='\0';
	
	int dp0[len]; 
	int dp1[len];

	memset(dp0, 0, sizeof(dp0));
	memset(dp1, 0, sizeof(dp1));

	dp0[0] = 1;
	dp1[0] = 1;
	for(i = 1; i < len; i++){
		dp0[i] = dp0[i - 1] + dp1[i - 1];
		dp1[i] = dp0[i - 1];
	}
	int cnt = dp0[len - 1] + dp1[len - 1];
	//printf("%d\n", cnt);
	for (i = len - 2; i >= 0; i--) {
		if (str[i] == '1' && str[i + 1] == '1') {
			break;
		}
		if (str[i] == '0' && str[i + 1] == '0') {
			cnt -= dp1[i];
			//printf(">>- %d %d\n", i, dp1[i]);
		}
	}
	return cnt;
}

int main(int argc, char *argv[])
{
	//printf("> %d \n", findIntegers(0xf));
	printf("> %d \n", findIntegers(0x10));
	printf("> %d \n", findIntegers(0x15));

	return 0;
}

