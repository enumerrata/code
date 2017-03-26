#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *f;
    struct ListNode *s;
    
    if (!head)
        return NULL;
    
    f = head;
    s = head;
    
    while (f && f->next ) {
        f = f->next->next;
        s = s->next;
        if (f == s) {
            break;
        }
    }
    
    if (!f || !f->next)
        return NULL;
    
    f = head;
    while (f != s) {
        f = f->next;
        s = s->next;
    }
    
    return f;
}
int main(int argc, char *argv[])
{
	struct ListNode a;
	struct ListNode b;

	a.val = 1;
	a.next = &b;
	b.val = 2;
	b.next = &a;


	printf("> %p\n", detectCycle(&a));

	return 0;
}

