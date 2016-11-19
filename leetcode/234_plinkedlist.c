#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool isPalindrome(struct ListNode* head) {
   int *stack;
   struct ListNode *p = head;
   int len=0;
   
   if (!head)
	   return true;
   stack = malloc(50000 * sizeof(int));
   while (p) {
	   stack[len++] = p->val;
	   p = p->next;
   }
   
   p = head;
   while (p) { 
	   if (p->val != stack[--len])
		   return false;
	   p = p->next;
   }
   
   return true;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

