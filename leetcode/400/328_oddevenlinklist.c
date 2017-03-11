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
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *odd = NULL;
    struct ListNode *even = NULL;
    struct ListNode *eh = NULL;

    if (!head)
        return NULL;

    odd = head;
    even = odd->next;
    eh = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = eh;
    
    return head;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

