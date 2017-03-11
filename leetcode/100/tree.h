#ifndef __TREE__H__
#define __TREE__H__

struct TreeLinkNode {
 int val;
 struct TreeLinkNode *left, *right, *next;
};

int min(int a, int b)
{
	return a < b ? a : b;
}

#endif
