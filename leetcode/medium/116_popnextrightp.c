#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *upper = root;
    struct TreeLinkNode *cur;
    
    while (upper && upper->left) {
        cur = upper;
        
        while (cur) {
            cur->left->next = cur->right;
            if (cur->next)
                cur->right->next = cur->next->left;
            cur = cur->next;
        }
        
        upper = upper->left;
    }
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

