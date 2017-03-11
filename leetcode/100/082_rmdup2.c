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
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode h;
    struct ListNode *pre;
    struct ListNode *p;
    struct ListNode *q;
    
    if (!head)
        return NULL;
    
    h.next = head;
    pre = &h;
    p = pre->next;

    while (p && p->next) {
        if (p->val != p->next->val) {
            pre->next = p;
            pre = p;
            p = p->next;
        } else {
            q = p->next;
            while (q->next && q->next->val == p->val)
                q = q->next;
            p = q->next;
            
        }
    }
    if (p)
        pre->next = p;
    else
        pre->next = NULL;
    return h.next;   
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

