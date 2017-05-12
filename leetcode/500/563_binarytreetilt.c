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
int sum1(struct TreeNode *r)
{
    if (!r)
        return 0;
    return r->val + sum1(r->left) + sum1(r->right);
}

int findTilt(struct TreeNode* root) {
    int sum = 0;
    
    if (!root)
        return 0;
        
    return abs(sum1(root->left) - sum1(root->right)) + findTilt(root->left)+findTilt(root->right);
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

