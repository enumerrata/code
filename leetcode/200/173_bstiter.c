#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode *stack[1000];
    int top;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *bs;
    struct TreeNode *cur = root;
    
    bs = malloc(sizeof(struct BSTIterator));
    bs->top = 0;
    
    while (cur) {
        bs->stack[bs->top++] = cur;
        cur = cur->left;
    }
    return bs;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    return iter->top > 0;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    struct TreeNode *cur;
    int ret;
    
    if (iter->top <= 0)
        return 0;
        
    cur = iter->stack[--iter->top];
    ret = cur->val;
    if (cur->right) {
        cur = cur->right;
        while (cur) {
            iter->stack[iter->top++] = cur;
            cur = cur->left;
        }
    }
    return ret;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    free(iter);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

