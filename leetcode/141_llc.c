#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool hasCycle(struct ListNode *head) {
    struct ListNode *f;
    struct ListNode *s;
    
    if (!head)
        return false;
    
    f = head->next;
    s = head;
    
    while (f && f->next ) {
        if (f == s)
            return true;
        f = f->next->next;
        s = s->next;
    }
    
    return false;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

