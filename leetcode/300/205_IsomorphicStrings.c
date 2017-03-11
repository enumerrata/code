#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

/*
1) If lengths of str1 and str2 are not same, return false.
2) Do following for every character in str1 and str2
   a) If this character is seen first time in str1, 
      then current of str2 must have not appeared before.
      (i) If current character of str2 is seen, return false.
          Mark current character of str2 as visited.
      (ii) Store mapping of current characters.
   b) Else check if previous occurrence of str1[i] mapped
      to same character.

  "egg", "add"
*/

bool isIsomorphic(char* s, char* t) {
    
	int map[CHAR_MAX];
	int appeared[CHAR_MAX];

	if (!strlen(s) || strlen(s) != strlen(t))
		return false;

	memset(map, -1, sizeof(map));
	memset(appeared, 0, sizeof(appeared));
	
	while (*s) {
		if (map[*s] == -1) {
			if (appeared[*t])
				return false;
			appeared[*t] = 1;
			map[*s] = *t;
		} else {
			if (map[*s] != *t)
				return false;
		}
	

		s++;
		t++;
	}

	return true;
}

int main(int argc, char *argv[])
{
	printf("> %d\n", isIsomorphic("eeg", "add"));

	return 0;
}

