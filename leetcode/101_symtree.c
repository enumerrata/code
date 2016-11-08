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

bool isSym(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)
        return true;
    if (!p && q)
        return false;
    if (p && !q)
        return false;
    if (p->val != q->val)
        return false;
    else
        return isSym(p->left, q->right) && isSym(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    if (root->left && !root->right) {
        return false;
    }
    
    if (!root->left && root->right) {
        return false;
    }
    
    if (root->left->val != root->right->val) {
        return false;
    }
    
    return isSym(root->left->left, root->right->right) && isSym(root->right->left, root->left->right);
}
int main(int argc, char *argv[])
{
	printf("> \n");
	return 0;
}
