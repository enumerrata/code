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
#if 0

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
#else

void gen(char *s, int slen, int start, int siz, int *sp, int top, char **p, int *len)
{
	int i;
	int num;

	if (start >= slen) {
		if (start == slen && top == 4) {
			char *a;
			a = malloc(64);
			sprintf(a, "%d.%d.%d.%d", sp[0],sp[1],sp[2],sp[3]);
			p[*len] = a;
			(*len)++;
			//printf("%d %d %d %d \n", sp[0],sp[1],sp[2],sp[3]);
		}
		return;	
	}

	if (siz <= 0)
		return; 

	for (i=start+1; i<=slen && i<start+4; i++) {
		num = valid(s, start, i);
		if (num >= 0) {
			sp[top++] = num;
			gen(s, slen, i, siz-1, sp, top, p, len);
			top--;
		}
	}

}

char** restoreIpAddresses(char* s, int* returnSize) {
	int len=strlen(s);
	int sp[100];
	char **p;

	*returnSize = 0;

	p = malloc(1000*sizeof(char *));
	gen(s, len, 0, 4, sp, 0, p, returnSize);

	return p;
}
#endif

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

