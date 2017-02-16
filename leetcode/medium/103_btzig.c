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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	struct TreeNode **s1;
	struct TreeNode **s2;
	int top1 = 0;
	int top2 = 0;
	int **p = malloc(sizeof(int *)*1000);
	int right = 1;
	int i;

	if (!root){
		*returnSize = 0;
		return NULL;
	}

	*columnSizes = malloc(sizeof(int) * 1000);
	
	s1 = malloc(sizeof(struct TreeNode *) * 1000);
	s2 = malloc(sizeof(struct TreeNode *) * 1000);

	s1[top1++] = root;
	*returnSize = 0;

	while (top1 || top2) {
		if (right) {
			//printf("top1 %d \n", top1);
			p[*returnSize] = malloc(sizeof(int) * top1);
			(*columnSizes)[*returnSize] = top1;
			for (i=0; i<top1; i++) {
				p[*returnSize][i] = s1[i]->val;
				if (s1[i]->left)
					s2[top2++] = s1[i]->left;
				if (s1[i]->right)
					s2[top2++] = s1[i]->right;
			}
			*returnSize += 1;
			top1 = 0;
			right = 0;
		} else {
			//printf("top2 %d \n", top2);
			p[*returnSize] = malloc(sizeof(int) * top2);
			(*columnSizes)[*returnSize] = top2;
			for (i=0; i<top2; i++) {
				p[*returnSize][top2-i-1] = s2[i]->val;
				if (s2[i]->left)
					s1[top1++] = s2[i]->left;
				if (s2[i]->right)
					s1[top1++] = s2[i]->right;
			}
			*returnSize += 1;
			top2 = 0;
			right = 1;
		}

	}
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

	p = zigzagLevelOrder(root, &columnSizes, &siz);

	for (i=0; i<siz; i++) {
		for (j=0; j<columnSizes[i]; j++)
			printf("%d ", p[i][j]);

		printf("\n");
	}


	return 0;
}

