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
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode n1 = {.next = NULL};
    struct ListNode n2 = {.next = NULL};
    struct ListNode *p, *q;
    
    p = &n1;
    q = &n2;
    
    while (head) {
        if (head->val < x) {
            p->next = head;
            p = p->next;
        } else {
            q->next = head;
            q = q->next;
        }
        
        head = head->next;
    }
    
    q->next = NULL;
    p->next = n2.next;
    
    return n1.next;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

