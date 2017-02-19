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

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

 struct TreeNode* getRoot(struct ListNode** head, int count) {
    if (count <= 0) {
        return NULL;
    }
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->left = getRoot(head, count / 2);
    root->val = (*head)->val;
	//printf("%d %d\n", root->val, count);
    (*head) = (*head)->next;
    root->right = getRoot(head, count - count / 2 - 1);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int cnt = 0;
    struct ListNode *t=head;
    
    if (!head)
        return NULL;
    
    while (t) {
        cnt++;
        t = t->next;
    }
    return getRoot(&head, cnt);
}

int main(int argc, char *argv[])
{
	struct ListNode a;
	struct ListNode b;
	struct ListNode c;

	a.val = 1;
	a.next = &b;
	b.val = 2;
	b.next = &c;
	c.val = 3;
	c.next = NULL;

	sortedListToBST(&a);

	return 0;
}

