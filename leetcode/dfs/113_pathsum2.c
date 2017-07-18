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

void pathsum(struct TreeNode* root, int sum, int *stack, int top, int** col, int* siz, int **p)
{
	int i;
	
	stack[top++] = root->val;
	sum -= root->val;
		
	if (!sum && !root->left && !root->right) {
		(*col)[*siz] = top;
		p[*siz] = malloc(sizeof(int) * top);
		memcpy(p[*siz], stack, sizeof(int) * top);
		*siz += 1;
		return;
	} 

    if (root->left)
	    pathsum(root->left, sum, stack, top, col, siz, p);
	if (root->right)	
	    pathsum(root->right, sum, stack, top, col, siz, p);

	return;	
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
	int **p;
	int stack[1000];
	int top = 0;

	if (!root)
		return NULL;

	p = malloc(sizeof(int *) * 1000);
	*columnSizes = malloc(sizeof(int) * 1000);
	*returnSize = 0;
   
   	pathsum(root, sum, stack, top, columnSizes, returnSize, p); 
	return p;
}

struct TreeNode* newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*)
                        malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main(int argc, char *argv[])
{
    struct TreeNode *root = newNode(3);
	int **p;
	int *columnSizes;
	int siz;
	int i,j;

    root->left        = newNode(9);
    root->right       = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);

	p = pathSum(root, 12, &columnSizes, &siz);

	for (i=0; i<siz; i++) {
		for (j=0; j<columnSizes[i]; j++)
			printf("%d ", p[i][j]);

		printf("\n");
	}

	return 0;
}

