#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>


#define HASHSIZ	100

struct val {
	int value;
	struct val *next;
};

uint32_t hash(int a)
{
	return a % HASHSIZ;
}

bool lookup(struct val **symtab, int value) 
{
	struct val *sym;
	int h;

	h = hash(value);

	for (sym=symtab[h]; sym; sym = sym->next) 
		if (value == sym->value)
			return true;
	sym = malloc(sizeof(struct val));
	sym->value = value;
	sym->next = symtab[h];
	symtab[h] = sym;
	return false;
}

struct val **hashinit(void)
{
	struct val **p;
	p = calloc(HASHSIZ, sizeof(struct val *));
	return p;
}

int main(int argc, char *argv[])
{
	struct val **symtab;

	symtab = hashinit();
	printf("%d \n", lookup(symtab, 0));
	printf("%d \n", lookup(symtab, 0));
	printf("%d \n", lookup(symtab, 5));
	printf("%d \n", lookup(symtab, 4));
	printf("%d \n", lookup(symtab, 104));


	return 0;
}

