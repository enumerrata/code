#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    int top;
    int *q;
    int size;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack->top = 0;
    stack->q = malloc((maxSize + 1) * sizeof(int));
    stack->size = maxSize;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    if (stack->top < stack->size) {
        stack->q[stack->top++] = element;
    }
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    if (stack->top > 0)
        stack->top--;
}

/* Get the top element */
int stackTop(Stack *stack) {
    return stack->q[stack->top - 1];
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return stack->top == 0;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    free(stack->q);
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

