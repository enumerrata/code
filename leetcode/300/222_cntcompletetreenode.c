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

#if 0 
int countNodes(struct TreeNode* root) {
    
    if (!root)
        return 0;
    
    return 1+countNodes(root->left) + countNodes(root->right);
}
#endif

int nodes(int h)
{
    int sum=1;
    
    while (h--)
        sum *= 2;
        
    return sum - 1;        
}

int countNodes(struct TreeNode* root) {
    int lh=0;
    int rh=0;
    struct TreeNode *t;
    
    if (!root)
        return 0;
    t = root;
    while (t->left) {
        t = t->left;
        lh += 1;
    }
    t = root;
    while (t->right) {
        t = t->right;
        rh += 1;
    }
    if (rh == lh) {
        return nodes(rh+1);
    }
    return 1+countNodes(root->left) + countNodes(root->right);
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

