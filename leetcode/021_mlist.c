#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *p;
	struct ListNode *q;

	if (!l1)
		return l2;

	if (!l2)
		return l1;

	if (l1->val <= l2->val) {
		p = l1;
		l1 = l1->next;
	} else {
		p = l2;
		l2 = l2->next;
	}
	q = p;

	while (l1 && l2) {
		if (l1->val <= l2->val) {
			p->next = l1;
			l1 = l1->next;
		} else {
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}

	if (l1)
		p->next = l1;

	if (l2)
		p->next = l2;

	return q;
    
}

int main(int argc, char *argv[])
{



	return 0;
}

