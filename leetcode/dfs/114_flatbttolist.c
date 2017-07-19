#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#if 0
void flatten(struct TreeNode* root) {
    struct TreeNode *t;
    
    if (!root)
        return;
    
    flatten(root->left);
    flatten(root->right);
    
    if (!root->left)
        return;
        
    t = root->left;
    while (t->right) {
        t = t->right;
    }
    
    t->right = root->right;
    root->right = root->left;
    root->left = NULL;
    
}
#else
void flatten(struct TreeNode* root) 
{
	struct TreeNode *cur;

	if (!root)
		return;
	
	while (root) {

		if (root->left ) {
            if (root->right) {
			    cur = root->left;

			    while (cur->right)
				    cur = cur->right;

			    cur->right = root->right;
            }
            root->right = root->left;
            root->left = NULL;
		} 
		      

		root = root->right;
	}

}
#endif

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

