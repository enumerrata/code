#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct item {
	char *s;
	int id;
};

int cmpc(const void *p1, const void *p2)
{
	return *(char *)p1 > *(char *)p2;
}

int cmpstr(const void *p1, const void *p2)
{
	struct item *i1 = (struct item *)p1;
	struct item *i2 = (struct item *)p2;

	return strcmp(i1->s, i2->s);
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
	char ***p = (char***)malloc(strsSize * sizeof(char *));
	int i,j;
	struct item *l;

	*columnSizes = malloc(sizeof(int) * strsSize);
	l = malloc(sizeof(struct item) * strsSize);
	*returnSize = 0;

	for (i=0; i<strsSize; i++) {
		l[i].s = strdup(strs[i]);
		l[i].id = i;
		qsort(l[i].s, strlen(l[i].s), 1, cmpc);
	}

	qsort(l, strsSize, sizeof(struct item), cmpstr);
	int start=0;
	int cnt=0;

	for (i=0; i<strsSize+1; i++) {
		if ((i == strsSize) || (strcmp(l[start].s, l[i].s))) {
			//printf("%d %d\n", start, cnt);
			p[*returnSize] = malloc(sizeof(char *) * cnt);
			for (j=0; j<cnt; j++) {
				p[*returnSize][j] = strs[l[start+j].id];
			}
			(*columnSizes)[*returnSize] = cnt;
			*returnSize += 1;
			start = i;
			cnt=1;
		} else {
			cnt++;
		}
	}

	return p;
}

int main(int argc, char *argv[])
{
    char **str;
    str = (char**)malloc(6 * sizeof(char*));

    str[0] = "eat";
    str[1] = "tea";
    str[2] = "tan";
    str[3] = "ate";
    str[4] = "nat";
    str[5] = "bat";

    int strsSize = 6;
    int* columnSizes;
    int returnSize;
    char ***result;
	int i,j;

    result = groupAnagrams(str, strsSize, &columnSizes, &returnSize);

	for (i=0; i<returnSize; i++) {
		for (j=0; j<columnSizes[i]; j++) {
			printf("%s ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}

