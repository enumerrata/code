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
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode *pre;
    struct ListNode *cur;
    struct ListNode *nex;

    if (!head)
        return NULL;
    
    dummy.val = INT_MIN;
    dummy.next = NULL;
    
    pre = &dummy;
    cur = head;
    
    while (cur) {
        nex = cur->next;
        while (pre->next && pre->next->val < cur->val)
            pre = pre->next;
            
        cur->next = pre->next;
        pre->next = cur;
        
        pre = &dummy;
        cur = nex;

    }
    return dummy.next;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

