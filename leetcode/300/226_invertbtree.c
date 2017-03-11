#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *t;
    
    if (!root)
        return NULL;
    
    t = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(t);
    
    return root;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

