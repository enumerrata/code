#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

/*
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }
*/

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

int main(int argc, char *argv[])
{
	char a[] = "23[abc34[cd]]56[xy]";
	int cur=0;

	//char a[] = "a2[c]";
	printf("%s", decodeString(a));

	return 0;
}

