#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     struct ListNode *next;
 };



struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode f;
	struct ListNode *p;
	struct ListNode *q;

    f.next = head;
    p = &f;
    q = p;
    
	while (n--) {
		p = p->next;
	}

	while (p->next) {
		p = p->next;
		q = q->next;
	}
    
	q->next =  q->next->next;
	
	if (q == &f) 
		return q->next;
	else
		return head; 
}

int main(int argc, char *argv[])
{
	struct ListNode a;
	struct ListNode b;
	struct ListNode c;

	struct ListNode *p;

	a.val = 'a';
	a.next = &b;

	b.val = 'b';
	b.next = NULL; //&c;

	c.val = 'c';
	c.next = NULL;

	p = removeNthFromEnd(&a, 2);

	while (p) {
		printf("%c\n", p->val);
		p=p->next;
	}
	return 0;
}

