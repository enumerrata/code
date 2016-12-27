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
int sumtree(struct TreeNode* root, int num) {
    int sum = 0;
    
    if (!root)
        return num;
    
    if (!root->left && !root->right)
        return num*10 + root->val;

    if (root->left)
        sum += sumtree(root->left, num*10 + root->val);
    if (root->right)
        sum += sumtree(root->right, num*10 + root->val);
        
    return sum;
}


int sumNumbers(struct TreeNode* root) {
    int sum = 0;
    
    return sumtree(root, 0);

}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

