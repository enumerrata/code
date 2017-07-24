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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void visit(struct TreeNode *root, int lvl, double *p, int *n, int *siz)
{
    if (!root)
        return;
    
    p[lvl] += root->val;
    n[lvl] += 1;
    *siz = *siz > lvl+1 ? *siz:lvl+1;
    
    visit(root->left, lvl+1, p, n, siz);
    visit(root->right, lvl+1, p, n, siz);

}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double *p;
    int *nums;
    int i;

    *returnSize = 0;
    if (!root) {
        return NULL;
    }
    
    p = calloc(1000, sizeof(double));
    nums = calloc(1000, sizeof(int));
    
    visit(root, 0, p, nums, returnSize);

    for (i=0; i<*returnSize; i++) {
        p[i] /= nums[i];
    }
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

