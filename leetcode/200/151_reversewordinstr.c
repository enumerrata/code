#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


void reverse(char *a, int i, int j)
{
	char t;
	//printf("%d %d \n", i, j);

	while (i < j) {
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++; j--;
	}
}

void reverseWords(char *s) {
    int len = strlen(s);
	int i;
	int inword = 0;
	int wlen = 0;
	int start = 0;
	int j=0;
	int blank=0;
	int head = 1;

	for (i=0; i<len; i++) {
		
		if (head && s[i] == ' ')
			continue;
		else
			head = 0;

		if (s[i] == ' ' && blank)
			continue;

		if (s[i] == ' ')
			blank = 1;
		else 
			blank = 0;

		s[j++] = s[i];
	}
	while (s[--j] == ' ')
		;
	s[++j] = '\0';
	//printf(">%s<\n", s, len);

	len = j;
	reverse(s, 0, len-1);

	for (i=0; i<len; i++) {
		if (!inword && s[i] != ' ') {
			start = i;
			inword = 1;
			wlen = 1;
		} else if (inword && s[i] == ' ') {
			inword = 0;
			if (wlen) 
				reverse(s, start, i-1);
		} else if (inword && s[i] != ' '){
			wlen++;
		}
	}
	reverse(s, start, len-1);

	return ;
}

int main(int argc, char *argv[])
{
	char a[] = "  the  sky is blue  ";
	//char a[] = "t";

	reverseWords(a);
	printf("> %s\n", a);

	return 0;
}

