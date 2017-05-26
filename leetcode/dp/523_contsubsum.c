#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <inttypes.h>

#include "../tree.h"

#if 0
/* sum%k same remainder is true */

bool checkSubarraySum(int* nums, int numsSize, int k) {
    int i,j,sum;
    
    for (i=0; i<numsSize-1; i++) {
        sum = nums[i];
        
        for (j=i+1; j<numsSize; j++) {
            sum += nums[j];
            if ((!k && sum == k) || (k && !(sum % k)))
                return true;
        }
    }
    
    return false;
}
#endif

#define HASHSIZ	100

struct val {
	int value;
	int pos;
	struct val *next;
};

uint32_t hash(int a)
{
	return a % HASHSIZ;
}

struct val *lookup(struct val **symtab, int value, int pos) 
{
	struct val *sym;
	int h;

	h = hash(value);

	for (sym=symtab[h]; sym; sym = sym->next) 
		if (value == sym->value)
			return sym;
	sym = malloc(sizeof(struct val));
	sym->value = value;
	sym->pos = pos;
	sym->next = symtab[h];
	symtab[h] = sym;
	return NULL;
}

struct val **hashinit(void)
{
	struct val **p;
	p = calloc(HASHSIZ, sizeof(struct val *));
	return p;
}


bool checkSubarraySum(int* nums, int numsSize, int k) {
    int i,j,sum=0;
    int pre=-1;
	struct val **symtab;
	struct val *p;

	symtab = hashinit();
    lookup(symtab, 0, -1);
    
    for (i=0; i<numsSize; i++) {
        sum += nums[i];
        if (k)
            sum %= k;
        if ((p=lookup(symtab, sum, i))) {
        // [0,1,0] 0 
            if (i - p->pos > 1)
                return true;
        }
    }
    
    return false;
}

int main(int argc, char *argv[])
{
	int a[] = {0,0};
	printf("> %d\n", checkSubarraySum(a, 2, 0));

	return 0;
}

