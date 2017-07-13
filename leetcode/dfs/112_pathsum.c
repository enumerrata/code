#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool sum1(struct TreeNode *r, int s) {
   
  
    if (!r->left && !r->right && r->val == s)
        return true;
    
    if (r->left) {
        if (sum1(r->left, s - r->val))
            return true;
    }
    
    if (r->right) {        
        if (sum1(r->right, s - r->val))
            return true;
    }
        
    return false;
}

bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root)
        return false;
    
    return sum1(root, sum); 
}

struct TreeNode* newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*)
                        malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
// 3
// 9 	20
// 15 7
// 12 38 30
int main(int argc, char *argv[])
{
    struct TreeNode *root = newNode(3);
    root->left        = newNode(9);
    root->right       = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);
	printf("> %d\n", hasPathSum(root, 30));

	return 0;
}

