#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *p;
    struct RandomListNode *t;
    
    if (!head)
        return NULL;
    
    p = head;
    while (p) {
        t = malloc(sizeof(struct RandomListNode));
        t->label = p->label;
        t->next = p->next;
        p->next = t;
        p = t->next;
    }
    p = head;
    while (p) {
        if (p->random)
            p->next->random = p->random->next;
        else
            p->next->random = NULL;
        p = p->next->next;
    }
    p = head;
    t = p->next;
    while (p) {    
        struct RandomListNode *tt;
        tt = p->next;
        p->next = p->next->next;
        p = p->next;
        if (tt->next)
            tt->next = tt->next->next;
    }
    return t;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

