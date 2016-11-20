#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* return root if left has one && right has one
 * return right if left none
 * return left  if right none
*/
struct TreeNode *lca(struct TreeNode *r, int v, int w)
{
    struct TreeNode *llca;
    struct TreeNode *rlca;
    
    if (!r)
        return r;
    
    if (r->val == v || r->val == w)
        return r;
    
    llca = lca(r->left, v, w);
    rlca = lca(r->right, v, w);
    
    if (llca && rlca)
        return r;
    
    return llca ? llca : rlca; 
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    
    if (!root)
        return root;
    
    return lca(root, p->val, q->val);
}



int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

