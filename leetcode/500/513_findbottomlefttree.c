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
 
void helper(struct TreeNode * r, int d, int *val, int *h) 
{
    if (!r)
        return;
    if (h < d) {
        *val = r->val;
        h = d;
    }
    
    helper(root->left, d+1);
    helper(root->right, d+1);
}

int findBottomLeftValue(struct TreeNode* root) {
    int val=0;
    int h=0;
    
    helper(r, 1, &val, &h);
    return val;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

