#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // a->b->c c->b->a
 // pre=>0 cur=a 
 // t=>b
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    struct ListNode *t;
    
    if (!head || !head->next)
        return head;
    
    while (cur) {
        t = cur->next;
        cur->next = pre;
        pre = cur;
        cur = t;
    }
    return pre;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

