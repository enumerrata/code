#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int lengthOfLongestSubstring(char* s) {
    int map[256] = {0};
    int len = strlen(s);
	int i,j;
	int max=0;

	for (i=0; i<len; i++) {
		memset(map, 0, sizeof(map));
		for (j=i; j<len; j++) {
			if (map[s[j]]) {
				//printf("%d %d %d\n", max, j-i+1, map[s[j]]);
				break;
			} else {
				map[s[j]]++;
			}
			if (j == len) j--;

			if ((j-i + 1) > max)
				max = j - i + 1;
		}

	}
	return max;
}
int main(int argc, char *argv[])
{
	printf(">  %d \n", lengthOfLongestSubstring("aba"));

	return 0;
}

