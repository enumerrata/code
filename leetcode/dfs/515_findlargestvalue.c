#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

#if 0
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
int* largestValues(struct TreeNode* root, int* returnSize) {
	int *p;
	int *siz = returnSize;
	struct TreeNode *q[1000];
	int in = 0;
	int out = 0;
	int max = INT_MIN;
	struct TreeNode *t;

	*siz = 0;
	p = malloc(sizeof(int) * 1000);

	if (!root)
		return NULL;
	
	q[in++] = root;
	q[in++] = NULL;

	while (out != in) {
		//printf("%d %d \n ", in, out);

		t = q[out++];out%=1000;

		if (t) {
			if (t->left) {
				q[in++] = t->left;
				in %= 1000;
			}
			if (t->right) {
				q[in++] = t->right;
				in %= 1000;
			}
			max = max < t->val ? t->val: max;
		} else {
			if (out != in) {
				q[in++] = NULL;
				in %= 1000;
			}
			p[*siz] = max;
			max = INT_MIN;
			*siz += 1;
		}
	}
   	return p; 
}
#else

void gen(struct TreeNode *root, int d, int *p, int *siz)
{
	if (!root)
		return;
	
    if (*siz < d+1) {
        p[d] = root->val;
        *siz += 1;
    } else {
        if (root->val > p[d])
		    p[d] = root->val;
    }
    
	gen(root->left, d+1, p, siz);
	gen(root->right, d+1, p, siz);
}

int* largestValues(struct TreeNode* root, int* returnSize) {
	int *p;

	p = calloc(1000, sizeof(int));
	*returnSize = 0;
    memset(p, INT_MIN, sizeof(int) * 1000);

	gen(root, 0, p, returnSize);
	return p;
    
}

#endif
int main(int argc, char *argv[])
{
	int *p;
	int siz;
	struct TreeNode a;
	struct TreeNode b;
	struct TreeNode c;
	int i = 0;

	a.val = 1;
	b.val = 3;
	c.val = 2;

	a.left = &b;
	a.right = &c;

	b.left = NULL;
	b.right = NULL;

	c.left = NULL;
	c.right = NULL;

	p = largestValues(&a, &siz);

	for (i=0; i<siz; i++) {
		printf("%d \n", p[i]);
	}

	return 0;
}

