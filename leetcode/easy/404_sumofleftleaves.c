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
int sumOfLeftLeaves(struct TreeNode* root) {
    int sum=0;
    
    if (!root)
        return 0;
        
    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val;
    
    if (root->right)
        sum += sumOfLeftLeaves(root->right);
    
    if (root->left)
        sum += sumOfLeftLeaves(root->left);
    
    return sum;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

