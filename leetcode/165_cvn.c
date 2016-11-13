#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int compareVersion(char* version1, char* version2) {
    char *p1 = version1;
    char *p2 = version2;
    int a=0, b=0;
    int next = 0;

	if (!*p1 && !*p2)
		return 0;

	while (*p1 || *p2) {
		a = b = 0;
		while (*p1) {
			if (*p1 == '.') {
				p1++;
				break;
			} else {
            	a = a*10 + *p1 - '0';
				p1++;
			}
		}

		while (*p2) {
			if (*p2 == '.') {
				p2++;
				break;
			} else {
            	b = b*10 + *p2 - '0';
				p2++;
			}
		}

		if (a>b) return 1;
		if (a<b) return -1;
	}
    
	if (a>b) return 1;
	if (a<b) return -1;
    return 0;
}

int main(int argc, char *argv[])
{
	printf("> %d\n", compareVersion("1", "1.1"));

	return 0;
}

