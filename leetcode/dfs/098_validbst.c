#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isValid(struct TreeNode *r, long long  max, long long  min)
{
    if (!r)
        return true;

    if (r->val <= min || r->val >= max)
        return false;
	
	return isValid(r->left, r->val, min) && isValid(r->right, max, r->val);
}

bool isValidBST(struct TreeNode* root) {
    if (!root)
        return true;
        
    if (!root->left && !root->right)
        return true;
    
    return isValid(root, INT_MAX+1ll, INT_MIN-1ll);
}

int main(int argc, char *argv[])
{
	printf("> %lld %lld\n", INT_MAX+1ll, INT_MIN-1ll);

	return 0;
}

