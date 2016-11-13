#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*
bool isInList(struct ListNode *h, struct ListNode *n)
{
    while (h) {
        if (h == n)
            return true;
        h = h->next;
    }   
    return false;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    while (headA) {
        if (isInList(headB, headA)) { 
            return headA;
        }
        headA = headA->next;
    }    
    
    return NULL;
}
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pa = headA;
    struct ListNode *pb = headB;
    struct ListNode *pae = NULL;
    struct ListNode *pbe = NULL;

    if (!headA || !headB)
        return NULL;
        
    if (headA == headB)
        return headA;

    while (1) {
        if (pa == pb)
            return pa;
        
        if (!pa->next) { 
            pae = pa;
            pa = headB;
        } else { 
            pa = pa->next;
        }
        
        if (!pb->next) {
            pbe = pb;
            pb = headA;
        } else {
            pb = pb->next;
        }
        
        if (pae && pbe && (pae != pbe))
            return NULL;
    }    
    
    return NULL;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

