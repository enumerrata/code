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

/* Driver program to test above functions*/
int main()
{
    struct TreeNode *root = newNode(3);
    root->left        = newNode(9);
    root->right       = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);

    return 0;
}



