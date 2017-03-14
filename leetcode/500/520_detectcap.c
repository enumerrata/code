#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tree.h"

bool detectCapitalUse(char* word) {
    if (isupper(*word)) {
        word++;
        if (*word && isupper(*word)) {
            while (*word) {
                if (!isupper(*word))
                    return false;
                word++;
            }
        } else if (*word && !isupper(*word)) {
            while (*word) {
                if (isupper(*word))
                    return false;
                word++;
            }
        }
        
    } else {
        while (*word) {
            if (isupper(*word))
                return false;
            word++;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

