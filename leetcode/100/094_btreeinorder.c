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

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int *p = malloc(sizeof(int) * 1000);
	struct TreeNode **stack =  malloc(sizeof(struct TreeNode *) * 1000);
	int cnt = 0, top = 0;
	struct TreeNode *cur = root;

	while (top > 0 || cur != NULL) {
		while (cur != NULL) {
			stack[top++] = cur;
			cur = cur->left;
		}
		cur = stack[--top];
		p[cnt++] = cur->val;
		if (cur->right) {
			cur = cur->right;
		} else {
			cur = NULL;
		}
	}
	*returnSize = cnt;
	return p;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

