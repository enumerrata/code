#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


//http://www.cnblogs.com/grandyang/p/5174738.html

bool isValidSerialization(char* preorder) {
	int cnt = 0;
	char *p;


	if (preorder[strlen(preorder) - 1] != '#')
		return false;

   	p = strtok(preorder, ",");
   	while (p) {
		if (*p == '#') {
			if (cnt == 0) {
				if (!strtok(NULL, ","))
					return true;
				else
					return false;
			}
			cnt--;
		} else {
			cnt++;
		}
		p = strtok(NULL, ",");
	}
   	return false; 
}

int main(int argc, char *argv[])
{
	char p[] = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	printf("> %d %d\n", isValidSerialization(p), sizeof(p));

	return 0;
}

