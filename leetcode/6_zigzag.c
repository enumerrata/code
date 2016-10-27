#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len =  strlen(s);
    int t=0;
    int i=0;
    int j=0;
    int f,l;
    int count=0;
    char *p,*q;

    if (len == 1 || len <= numRows || numRows == 1)
        return s;

    p = malloc(len);
	q = p;
    count = 2*numRows -2;

    f = count;
    l = 0;
    while (numRows >= 1) {
        j = 1;
        i = t;
        while (i < len) {
            *p = s[i];
			p++;
			if (!f || !l) {
				i += count;
				continue;
			}

            if (j++ % 2)
                i += f;
            else
                i += l;
        }
        
        numRows--;
        t++;
        f -= 2;
        l += 2;
    }
    return q;
}

int main(int argc, char *argv[])
{
	char *p;
	p = convert("abc", 2);
	printf("%s, %d", p, strlen(p));
	return 0;
}
