#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// a->b->c->d->e->f  q->a h/p->b t->c
// b->a->d->c->f->e
struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode *p;
	struct ListNode *q;
	struct ListNode *t;
	struct ListNode *hh;
	struct ListNode *h;

	if (!head)
		return head;

	hh = head->next;
	q = head;
	p = q->next;
	if (!p)
	    return head;
	t = p->next;

	p->next = q;
	h = q;

	while (t) {
		q = t;
		p = q->next;
		if (!p) { 
		    h->next = q;
		    return hh;
		}
		t = p->next;

        
		h->next = p;
		p->next = q;
		h = q;
	}
	
	h->next = NULL;

   	return hh; 
}

int main(int argc, char *argv[])
{



	return 0;
}

