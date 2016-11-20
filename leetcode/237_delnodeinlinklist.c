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
void deleteNode(struct ListNode* node) {

    if (!node || !node->next)
        return;
        
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

