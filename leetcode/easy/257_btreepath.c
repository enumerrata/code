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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *str(int *path, int len)
{
	char *p,*q;
	int i;

	p = malloc(sizeof(char) * 13 * (len+1));
	q = p;

	for (i=0; i<len; i++) {
		p += sprintf(p, "%d->", path[i]);
	}
	p--; p--;
	*p = '\0';
	return q;
}

void printpath(struct TreeNode *r, int *path, int len, char **p, int *retsize)
{
    if (!r)
        return;
    
	path[len++] = r->val;

    if (!r->left && !r->right) {
		//printf(">> len %d %d\n", len, r->val);
		p[*retsize] = str(path, len);
		*retsize += 1;
		return;
	}

	if (r->left)
		printpath(r->left, path, len, p, retsize);
    
	if (r->right)
		printpath(r->right, path, len, p, retsize);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char **p;
    int path[1000];
    
    *returnSize = 0;
	p =  malloc(sizeof(char *) * 1000);

	printpath(root, path, 0, p, returnSize);

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
/* 3
		9
		20 
			15
			7
3->9
3->20->15
3->20->7
 */
int main(int argc, char *argv[])
{
    struct TreeNode *root = newNode(3);
	char **p;
	int size;
	int i;

    root->left        = newNode(9);
    root->right       = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);

	p = binaryTreePaths(root, &size);

	for (i=0; i<size; i++) {
		printf("%s \n", p[i]);
	}

	return 0;
}

