#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int cmpstr(const void *p1, const void *p2)
{
    char tmp1[20]={0};
    char tmp2[20]={0};
    
    strcat(tmp1, * (char **) p1);
    strcat(tmp1, * (char **) p2);
    
    strcat(tmp2, * (char **) p2);
    strcat(tmp2, * (char **) p1);

    printf(">> %s %s\n", tmp1, tmp2);
	return strcmp(tmp2, tmp1);
}

char* largestNumber(int* nums, int numsSize) {
    char **l = malloc(sizeof(char *) * numsSize);
    int i;
	char *p = malloc(sizeof(char *) * 1000);

	p[0] = '\0';
    
    for (i=0; i<numsSize; i++) {
        l[i] = malloc(sizeof(char) * 12);
        sprintf(l[i], "%d", nums[i]);
    }

	qsort(l, numsSize, sizeof(char *), cmpstr);

	for (i=0; i<numsSize; i++) {
	    if (strlen(p) == 1 &&  p[0] == '0' && !strcmp(l[i], "0"))
	        continue;
		strcat(p, l[i]);
	}
   	return p;
}
int main(int argc, char *argv[])
{
	int a[] = {1, 0, 0};

	printf("> %s\n", largestNumber(a, 3));

	return 0;
}

