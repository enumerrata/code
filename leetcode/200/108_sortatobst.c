#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	struct TreeNode *t = NULL;
	int i;

	if (inorderSize <= 0)
		return NULL;

	for (i=0; i<inorderSize; i++) {
		if (preorder[0] == inorder[i])
			break;
	}

	t = malloc(sizeof(struct TreeNode));
	t->val = preorder[0];
    t->left = buildTree(&preorder[1], i, inorder, i);
    t->right = buildTree(&preorder[i+1], preorderSize - 1 - i, &inorder[i+1], preorderSize - 1 - i);

   	return t; 
}


int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

