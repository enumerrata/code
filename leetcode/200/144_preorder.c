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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *p = malloc(sizeof(int) * 1000);
    struct TreeNode **stack;
    struct TreeNode *t;
    int top = 0;
    int len = 0;
    
    if (!root)
        return NULL;
        
    stack = malloc(sizeof(struct TreeNode *) * 1000);
    stack[top++] = root;

    while (top > 0) {
        t = stack[--top];
        p[len++] = t->val;
        if (t->right) {
            stack[top++] = t->right;
        }
        if (t->left) {
            stack[top++] = t->left;
        }
    }
    *returnSize = len;
    return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

