#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *pre = root;
    struct TreeLinkNode *cur = NULL;
    struct TreeLinkNode *p = NULL;
    struct TreeLinkNode *c = NULL;
    
    while (pre) {
        p = pre;
        
        while (p) {
            if (p->left) {
                if (cur == NULL) {
                    cur = p->left;
                    c = cur;
                } else {
                    c->next = p->left;
                    c = c->next;
                }
            }
            
             if (p->right) {
                if (cur == NULL) {
                    cur = p->right;
                    c = cur;
                } else {
                    c->next = p->right;
                    c = c->next;
                }
            }
                     
            p = p->next;
        }
        
        pre = cur;
        cur = NULL;
    }
    
    
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

