#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void add(int v, struct TreeNode *r, int *num, int *sum)
{
    r->val += v;
    
    if (!r->left && !r->right) {
        sum[*num] = r->val;
        *num += 1;
    }
    
    if (r->left)
        add(r->val, r->left, num, sum);
    
    if (r->right)
        add(r->val, r->right, num, sum);
}

bool hasPathSum(struct TreeNode* root, int sum) {
    int *suml = malloc(10000 * sizeof(int));
    int num=0;
    int i;
    
    if (!root)
        return false;
    
    add(0, root, &num, suml);

    for (i=0; i<num; i++) {
		//printf("%d \n", suml[i]);
        if (suml[i] == sum)
            return true;
    }
    return false;
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
// 3
// 9 	20
// 15 7
// 12 38 30
int main(int argc, char *argv[])
{
    struct TreeNode *root = newNode(3);
    root->left        = newNode(9);
    root->right       = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);
	printf("> \n");

	hasPathSum(root, 100);

	return 0;
}

