#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int cnt = 0, t;
    struct ListNode *cur = head;
    struct ListNode *nxt=NULL, *last=NULL;
    
    while (cur) {
        cnt++;
        cur = cur->next;
    }
    cnt = cnt - cnt % k;
    cur = head;
    t = k;
    
    while (cnt--) {
        if (--t) {
            nxt = cur->next;
            cur->next = cur->next->next;
            nxt->next = !last?head:last->next;
            head = !last?nxt:head;
            if (last)
                last->next = nxt;
            
        } else {
            last = cur;
            cur = cur->next;
            t = k;
        }
    }
    return head;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

