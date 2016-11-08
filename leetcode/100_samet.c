#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };

 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)
        return true;

    if (!p && q)
        return false;

    if (p && !q)
        return false;

    if (p->val != q->val)
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

