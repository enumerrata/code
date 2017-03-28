#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k) {
    int i = 0;
    struct TreeNode *st[1000];
    struct TreeNode *cur = root;
    int top = 0;
    
    while (cur || top>0) {
        while (cur) {
            st[top++] = cur;
            cur = cur->left;
        }
        cur = st[--top];
        if (k == ++i) 
            return cur->val;
        if (cur->right)
            cur = cur->right;
        else
            cur = NULL;
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

