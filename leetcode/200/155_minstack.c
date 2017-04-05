#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

typedef struct {
    int value;
    int curmin;
} Element;

typedef struct {
    int min;
    Element *st;
    int top;
    int siz;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *stack;
    
    stack = malloc(sizeof(MinStack));
    stack->st = malloc(sizeof(Element) * maxSize);
    stack->top = 0;
    stack->siz = maxSize;
    stack->min = 0;
    
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    Element *st = obj->st;
    
    if (obj->top < obj->siz) {
        if (obj->top && st[obj->top-1].curmin < x) {
            st[obj->top].curmin = st[obj->top - 1].curmin;
        } else {
            st[obj->top].curmin = x;
        }
        st[obj->top].value = x;
        obj->top++;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top)
        return obj->st[obj->top - 1].value;
    return 0;
}

int minStackGetMin(MinStack* obj) {
    return obj->st[obj->top - 1].curmin;
}

void minStackFree(MinStack* obj) {
    free(obj->st);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

