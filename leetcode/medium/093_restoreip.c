#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int isvalid(char *s, int start, int end) 
{
	int sum = 0;

	if (s[start] == '0' && end-start == 1)
		return 0;

	if (s[start] == '0' && end-start != 1)
		return -1;

	while (start < end) {
		sum = sum * 10 + s[start] - '0';
		start++;
	}
	//printf(" %d\n", sum);

	return sum > 255 ? -1 : sum;
}


void ria(char *s, int slen, int start, int *stack, int top, char **p, int *retsiz)
{
	if (0){
		int j=0;
		printf("%d: ", top);
		for (j=0; j<top; j++)
			printf("%03d ", stack[j]);
		printf("\n");
	}
	if (top == 4 && start != slen)
		return;
	
	if (top == 4) {
		p[*retsiz] = malloc(16);
		sprintf(p[*retsiz], "%d.%d.%d.%d", stack[0], stack[1], stack[2], stack[3]);
		*retsiz += 1;
		return;
	}

	int i;
	int tmp;

	for (i=start; i<slen && i < start + 3; i++) {
		tmp = isvalid(s, start, i+1); 
		if (tmp >= 0) {
			stack[top++] = tmp;
			ria(s, slen, i+1, stack, top, p, retsiz);
			top--;
		}
	}
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
	char  **p = malloc(sizeof(char *) * 1000);
	int stack[4];
	int top = 0;

	*returnSize = 0;
	ria(s, strlen(s), 0, stack, top, p, returnSize);
    
	return p;
}

int main(int argc, char *argv[])
{
    char *a = "25525511135";
	char **p;
	int siz;
	int i;

	p = restoreIpAddresses(a, &siz);

	for (i=0; i<siz; i++)
		printf("%s\n", p[i]);

	return 0;
}

