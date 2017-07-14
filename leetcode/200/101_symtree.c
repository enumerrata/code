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

    
    return isSym(root->left, root->right);
}

int main(int argc, char *argv[])
{
	printf("> \n");
	return 0;
}
