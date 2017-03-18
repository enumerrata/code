#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

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
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *p = malloc(sizeof(int) * 1000);
    struct TreeNode *q[1000];
	int wr=0;
	int rd=0;
    
    if (!root)
        return NULL;

	q[wr++] = root;
	q[wr++] = NULL;
	*returnSize = 0;
    
    while (rd != wr) {
		struct TreeNode *cur;
		cur = q[rd++];

		if (!cur) {
			if (rd == wr)
				break;
			else
				q[wr++] = NULL;
		} else {
			if (!q[rd]) {
				p[*returnSize] = cur->val;	
				*returnSize += 1;
			}
			if (cur->left)
				q[wr++] = cur->left;

			if (cur->right)
				q[wr++] = cur->right;
		}
	}

	return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

