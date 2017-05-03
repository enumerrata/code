#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


     
struct ListNode *merge2list(struct ListNode *head1, struct ListNode*head2)
{
	struct ListNode node={0}; 
	struct ListNode *res = &node;

	while(head1 && head2) {
		if(head1->val <= head2->val) {
			res->next = head1;
			head1 = head1->next;
		} else {
			res->next = head2;
			head2 = head2->next;
		}
		res = res->next;
	}

	if(head1)
		res->next = head1;
	else if(head2)
		res->next = head2;

	return node.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	int i;
	
	if (listsSize == 0)
		return NULL;

	while (listsSize > 1) {
		int k = (listsSize+1)/2;

		for(i = 0; i < listsSize/2; i++)
			lists[i] = merge2list(lists[i], lists[i + k]);

		listsSize = k;
	}
	return lists[0];
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

