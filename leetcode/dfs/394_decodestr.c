#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

#if 0
char* decodeStr(char* s, int *cur) {
	char *p = calloc(10000, 1);
	char *t;
	int top=0;

	//printf("%s\n",  &s[*cur]);
	while (s[*cur] && s[*cur] != ']' ) {
		if (!isdigit(s[*cur])) {
			top = strlen(p); 
			p[top++] = s[(*cur)++];	
		} else {
			int n = 0;
			while (s[*cur] && isdigit(s[*cur]))
				n = n * 10 + s[(*cur)++] - '0';

			(*cur)++; // [
			t = decodeStr(s, cur);
			//printf("%d %s\n",n,t);
			(*cur)++; // ]

			while (n--)
				strcat(p, t);
		}

	}
	return p;
}

char* decodeString(char* s) {
	int cur = 0;
	return decodeStr(s, &cur);
}
#else

int repeatn(char *p, int n)
{
	int l = strlen(p);	
	int i;

	for (i=1; i<n; i++) {
		memcpy(p+i*l, p, l);
	}

	return l*n;
}

char* decodeString(char* s) {
	int i=0;
	int nstack[1000];
	int cstack[1000];
	int ntop = 1;
	char *sstack[1000];

	sstack[0] = calloc(10000, 1);
    cstack[0] = 0;

	while (s[i]) {
		if (isdigit(s[i])) {
			int n = 0;
			while (s[i] && isdigit(s[i]))
				n = n * 10 + s[i++] - '0';
			cstack[ntop] = 0;
			nstack[ntop] = n;
			sstack[ntop] = malloc(10000);
			ntop++;
			i++; //skip [
		} else {
			if (s[i] == ']') {
				int l;
				sstack[ntop-1][cstack[ntop-1]] = '\0';
				l = repeatn(sstack[ntop-1], nstack[ntop-1]);
				//printf("%s %d\n", sstack[ntop-1], nstack[ntop-1]);
				memcpy(&sstack[ntop-2][cstack[ntop-2]], sstack[ntop-1], l);
				cstack[ntop-2] += l;
				//printf("%s %d\n", sstack[ntop-2], cstack[ntop-2]);
				ntop--;

			} else {
				sstack[ntop-1][cstack[ntop-1]] = s[i];
				cstack[ntop-1] += 1;
			}
			i++;
		}

	}
	return sstack[0];
}

#endif

int main(int argc, char *argv[])
{
	char a[] = "slkjdf34[b]";
	int cur=0;

	printf("%s\n", decodeString(a));

	return 0;
}

