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
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *p;
    struct ListNode *q;
    int len=0;

    int i;

    if (!head) return NULL;
    
    if (!head->next) return head;
    
    p = head;
    while (p) {
        p = p->next;
        len++;
    }
    k = k % len;
    
    if (!k) return head;
    
    p = head;
    for (i=0; i<k; i++) {
        p = p->next;
    }
    q = head;
    
    while (p->next) {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    p=q->next;
    q->next = NULL;
    
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

