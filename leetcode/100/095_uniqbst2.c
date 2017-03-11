#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode** generate(int start, int end, int* siz) {
    int k, i, j;
    int lsize, rsize;
    struct TreeNode **ltree, **rtree, **p;
    p = (struct TreeNode**)malloc(sizeof(struct TreeNode*));

    if (start > end) {
        p[0] = NULL;
        *siz = 1;
        return p;
    }

    *siz = 0;
    for (k = start; k <= end; k++) {
        ltree = generate(start, k - 1, &lsize);
        rtree = generate(k + 1, end, &rsize);
        for (i = 0; i < lsize; i++) {
            for (j = 0; j < rsize; j++) {
                p = realloc(p, (*siz + 1) * sizeof(struct TreeNode*));
                p[*siz] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                p[*siz]->val = k;
                p[*siz]->left = ltree[i];
                p[*siz]->right = rtree[j];
                *siz += 1;
            }
        }
    }
    return p;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize) {

	if (n == 0) {
		*returnSize = 0;
		return NULL;
	}

	return generate(1, n, returnSize);
}

int main(int argc, char *argv[])
{
	int siz;

	generateTrees(3, &siz);
    printf("> \n");

    return 0;
}

