#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*)
                        malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void prval(int v, int lvl)
{
	while (lvl-- > 0)
		printf("  ");
	printf("%d", v);
	printf("\n");
}

void prtree_r(struct TreeNode *r, int lvl)
{
	if (r) {
		prval(r->val, lvl);
		if (r->left)
			prtree_r(r->left, lvl+1);
		if (r->right)
			prtree_r(r->right, lvl+1);
	}
}

void prtree(struct TreeNode *r)
{
	prtree_r(r, 0);
}

/* Driver program to test above functions*/
int main()
{
    struct TreeNode *root = newNode(3);
    root->left        = newNode(9);
    root->right       = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);

	prtree(root);
    return 0;
}



