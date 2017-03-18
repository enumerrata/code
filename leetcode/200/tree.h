#ifndef __TREE__H__
#define __TREE__H__

struct TreeLinkNode {
 int val;
 struct TreeLinkNode *left, *right, *next;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
#endif
