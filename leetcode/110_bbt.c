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
 
int depth(struct TreeNode* root)
{
    int d1;
    int d2;
    
    if (!root)
        return 0;
        
    d1 = depth(root->left);
    d2 = depth(root->right);
    
    return d1 > d2 ? d1+1: d2+1; 
}

bool isBalanced(struct TreeNode* root) {
    int d1;
    int d2;
    
    if (!root)
        return true;
    
    d1 = depth(root->left);
    d2 = depth(root->right);
    
    if ((d1 == d2 + 1) || (d2 == d1 + 1) || (d1 == d2))
        return isBalanced(root->left) && isBalanced(root->right);
        
    return false;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

