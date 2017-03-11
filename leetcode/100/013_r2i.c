#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getRomanValue(char c) {
	switch(c) {  
		case 'I': return 1;   
		case 'V': return 5;  
		case 'X': return 10;  
		case 'L': return 50;  
		case 'C': return 100;  
		case 'D': return 500;  
		case 'M': return 1000;  
		default: return 0;  
	}  
}  

int romanToInt(char* s) {
	int pre=0;
	int cur=0;
	int sum = 0;

	if (strlen(s) < 1)
		return 0;
	
	while (*s) {
		cur = getRomanValue(*s);

		if (cur > pre) {
			sum += cur - pre -pre;
			pre = cur;
		} else {
			sum += cur;
			pre = cur;
		}
		s++;
	}

	return sum;
}

int main(int argc, char *argv[])
{

	printf("%d \n", romanToInt("XIIV"));
	printf("%d \n", romanToInt("IX"));

	return 0;
}

