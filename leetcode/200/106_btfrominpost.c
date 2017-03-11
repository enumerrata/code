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


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	struct TreeNode *t = NULL;
	int i;

	if (inorderSize <= 0)
		return NULL;

	for (i=0; i<inorderSize; i++) {
		if (postorder[postorderSize - 1] == inorder[i])
			break;
	}
    
	t = malloc(sizeof(struct TreeNode));
	t->val = inorder[i];
    t->left = buildTree(inorder, i, &postorder[0], i);
    t->right = buildTree(&inorder[i+1], postorderSize - 1 - i, 
		&postorder[i], postorderSize - 1 - i);

   	return t; 
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

