#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode p;
    struct ListNode *q;
    int c = 0;

    q = &p;

    while (l1 && l2) {
        q->next = malloc(sizeof(struct ListNode));
        q = q->next;
        q->val = (l1->val + l2->val + c) % 10;
        c = (l1->val + l2->val + c >= 10);
        l1 = l1->next; l2 = l2->next;
    }
    while (l1) {
        q->next = malloc(sizeof(struct ListNode));
        q = q->next;
        q->val = (l1->val + c) % 10;
        c = (l1->val + c >= 10);
        l1 = l1->next;
    }
    while (l2) {
        q->next = malloc(sizeof(struct ListNode));
        q = q->next;
        q->val = (l2->val + c) % 10;
        c = (l2->val + c >= 10);   
		l2 = l2->next;
    }
    if (c) {
        q->next = malloc(sizeof(struct ListNode));
        q = q->next;
        q->val = 1;
    }
    q->next = NULL;
    
    
    return p.next;
}

int main(int argc, char *argv[])
{
	struct ListNode a;
	struct ListNode b;
	struct ListNode c;
	struct ListNode d;

	a.val = 1;
	a.next = &b;
	b.val = 2;
	b.next = NULL;

	c.val = 1;
	c.next = &b;
	d.val = 2;
	d.next = NULL;

	printf("> %p\n", addTwoNumbers(&a, &b));

	return 0;
}

