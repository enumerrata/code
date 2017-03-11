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
void flatten(struct TreeNode* root) {
    struct TreeNode *t;
    
    if (!root)
        return;
    
    flatten(root->left);
    flatten(root->right);
    
    if (!root->left)
        return;
        
    t = root->left;
    while (t->right) {
        t = t->right;
    }
    
    t->right = root->right;
    root->right = root->left;
    root->left = NULL;
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

