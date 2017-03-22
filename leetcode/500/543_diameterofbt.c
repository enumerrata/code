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
 int dep(struct TreeNode *r) {
    int d1=0,d2=0;
     
    if (!r)
        return 0;
    
    if (r->left)
        d1 = dep(r->left) + 1;
    if (r->right)
        d2 = dep(r->right) + 1;
    
     return d1>d2?d1:d2;
 }
 int max(int a, int b)
 {
     return a>b?a:b;
 }
 
int diameterOfBinaryTree(struct TreeNode* root) {
    int d = 0;
    int dl, dr;
    
    if (!root)
        return 0;
    
    if (root->left)
        d += dep(root->left)+1;
    if (root->right)
        d += dep(root->right)+1;
    
    dl = diameterOfBinaryTree(root->left);
    dr = diameterOfBinaryTree(root->right);
    
    
    return max(d, max(dl, dr));
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

