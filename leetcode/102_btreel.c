#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
// [[3], [9,20], [15,7]]
// [ 1,   2,      2]
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (!root) {
		*returnSize = 0;
        return NULL;
	}

	int **list = malloc(1000*sizeof(int *));
	int *sizlist = malloc(1000*sizeof(int));
	struct TreeNode *queue[2000];
	int len = 1;
	int nlen = 0;
	int ss = 0;
	int ee = 0;
	int lvl = 0;

	queue[ee++] = root;

	while (len > 0) {
		int *l = malloc(len * sizeof(int));
		int i;

		sizlist[lvl] = len; 
		list[lvl++] = l;
		nlen = 0;

		for (i=0; i < len; i++) {
			struct TreeNode *t;

			t = queue[ss++];
			l[i] = t->val;

			if (t->left) {
				nlen++;
				queue[ee++] = t->left;
			}
			if (t->right) {
				nlen++;
				queue[ee++] = t->right;
			}
		}
		len = nlen;
	}

	*returnSize = lvl;
	*columnSizes = sizlist;

	return list;
}

struct TreeNode *new(int val)
{
	struct TreeNode *n = malloc(sizeof(struct TreeNode));

	n->val = val;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}

int main(int argc, char *argv[])
{
	int **l;
	int *line;
	struct TreeNode *r = new(3);
	int *columnSizes;
	int returnSize;
	int i,j;

	r->left = new(9);
	r->right = new(20);
	r->right->left = new(15);
	r->right->right = new(7);

	l = levelOrder(r, &columnSizes, &returnSize);

	printf("%d %d %d\n", returnSize, columnSizes[0], columnSizes[1]);

	for (i=0; i<returnSize; i++) {
		line = l[i];
		for (j=0; j<columnSizes[i]; j++) {
			printf("%d ", line[j]);
		}
		printf("\n");
	}



	return 0;
}

