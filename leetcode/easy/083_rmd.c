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
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode *p = head;
    
	if (!head)
		return NULL;

	while (p->next) {
		if (p->val == p->next->val) {
			p->next = p->next->next;
		} else {
			p = p->next;
		}
	}
	
	return head;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

