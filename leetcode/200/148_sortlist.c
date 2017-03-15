#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *merge(struct ListNode *l, struct ListNode *r)
{  
	struct ListNode temp;
	struct ListNode *p = &temp;  

	while(l && r){  
		if(l->val<=r->val){  
			p->next = l;  
			l = l->next;  
		}  else{  
			p->next = r;  
			r = r->next;  
		}  
		p = p->next;  
	}  

	if(!l)  
		p->next=r;  
	else  
		p->next=l;  

	return temp.next;  
}

struct ListNode *mergeSort(struct ListNode *head)
{  
	struct ListNode *p=head, *q=head, *pre=NULL;  

	if (!head || !head->next)
		return head;  

	while (q && q->next){  
		q = q->next->next;  
		pre = p;  
		p = p->next;
	}  

	pre->next = NULL;  
	q = mergeSort(head);  
	p = mergeSort(p);

	return merge(q, p);   //merge  
}  

struct ListNode* sortList(struct ListNode* head) {
	struct ListNode *f=head;
	struct ListNode *s;

	if (!f || !f->next)
		return head;

   	return mergeSort(head); 
}



int main(int argc, char *argv[])
{
	struct ListNode a;
	struct ListNode b;
	struct ListNode c;
	struct ListNode d;

	struct ListNode *p;

	a.val = 2;
	a.next = &b;
	b.val = 5;
	b.next = &c;
	c.val = 1;
	c.next = &d;
	d.val = 4;
	d.next = NULL;

	p = sortList(&a);
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}

	return 0;
}

