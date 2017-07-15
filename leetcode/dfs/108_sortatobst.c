#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int m;
    struct TreeNode *p;
    
    if (numsSize <= 0)
        return NULL;
    
    m = numsSize/2;
    p = malloc(sizeof(struct TreeNode));
    
    p->val = nums[m];    
    p->left = sortedArrayToBST(nums, m);
    p->right = sortedArrayToBST(&nums[m+1], numsSize-m-1);
    
    return p;
}


int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

