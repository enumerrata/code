#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root) {
    int m1;
    int m2;
    
    if (!root)
        return 0;
    
    if (!root->left && !root->right)
        return 1;
    
    if (!root->left)
        return minDepth(root->right) + 1;
    
    if (!root->right)
        return minDepth(root->left) + 1;

    
    m1 = minDepth(root->left);
    m2 = minDepth(root->right);
    
    return m1 > m2 ? m2 + 1 : m1 + 1; 
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

