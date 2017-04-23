#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

int min_(int a, int b) 
{
    return a<b? a:b;
}
 
int helper(struct TreeNode *root) {
    int left = INT_MAX;
    int right = INT_MAX;

    if(root->left != NULL) {
        struct TreeNode *temp = root->left;
        while(temp->right != NULL) temp = temp->right;
        left = min_(left, abs(root->val - temp->val));
    }
    
    if(root->right != NULL) {
        struct TreeNode *temp = root->right;
        while(temp->left != NULL) temp = temp->left;
        right = min_(right, abs(root->val - temp->val));
    }
    return min_(left, right);
}
int getMinimumDifference(struct TreeNode* root) {
	int min = INT_MAX;
    
	if (root->left || root->right)
		min = min_(min, helper(root));

    if (root->left) {
        min = min_(min, getMinimumDifference(root->left));
    }
    
    if (root->right) {
        min = min_(min, getMinimumDifference(root->right));
    }
    
	return min;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

