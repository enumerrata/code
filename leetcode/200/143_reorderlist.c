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

void reorderList(struct ListNode* head) {
    struct ListNode *p,*q;
    
    if (!head || !head->next || !head->next->next)
        return ;
        
    p = head;
    while (p->next->next) 
        p = p->next;
    
    q = p->next;
    p->next = NULL;
    
    //printf("%d \n", q->val);
    q->next = head->next;
    head->next = q;
    
    reorderList(q->next);
}
 */
// O(N) time, O(1) space in total
void reorderList(struct ListNode *head) {
    if (!head || !head->next) return;
    
    // find the middle node: O(n)
    struct ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    struct ListNode *head2 = p1->next;
    p1->next = NULL;
    
    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }
    
    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }

}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

