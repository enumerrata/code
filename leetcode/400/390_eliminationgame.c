#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int lastRemaining(int n) {
	int remain=n;
	int left=1;
	int step=2;
	int head=1;

	while (remain > 1) {
		if (left) {
			head = head + step/2;
		} else {
			if (remain % 2) {
				head = head + step/2;
			}
		}
		left = !left;
		step *= 2;
		remain/=2;
		//printf("%d \n", head);
	}
   	return head; 
}

int main(int argc, char *argv[])
{
	printf("> %d\n", lastRemaining(9));

	return 0;
}

