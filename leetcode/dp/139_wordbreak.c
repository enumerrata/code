#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

#if 0
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int sLength = strlen(s);
    bool *isBreakable = (bool*)malloc(sLength * sizeof(sLength));
    char *subString = (char*)malloc(sLength * sizeof(char));
    bool isLastSubstringBreakable;
    int i = 0;
    int j = 0;
    int k = 0;

    isBreakable[0] = false;
    for (i = 0; i < wordDictSize; ++i) {
        if ((1 == strlen(wordDict[i])) && (s[0] == wordDict[i][0])) {
            isBreakable[0] = true;
            break;
        }
    }

    for (i = 1; i < sLength; ++i) {
        isBreakable[i] = false;
        for (j = -1; j < i; ++j) {
            if (-1 == j) {
                isLastSubstringBreakable = true;
            } else {
                isLastSubstringBreakable = isBreakable[j];
            }
            if (isLastSubstringBreakable) {
                strncpy(subString, s + j + 1, i - j);
                subString[i - j] = '\0';
                for (k = 0; k < wordDictSize; ++k) {
                    if (0 == strcmp(subString, wordDict[k])) {
                        isBreakable[i] = true;
                        break;
                    }
                }
            }
        }
    }
    
    return isBreakable[sLength - 1];
}
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
	int len =  strlen(s);
	bool *canSegment = malloc(sizeof(bool) * (len + 1));
    char *subString = (char*)malloc((len+1) * sizeof(char));
	int i,j,k;


	canSegment[0] = true;
	for (i = 1; i <= len; i++) {
		canSegment[i] = false;
		for (j = 1; j <= i; j++) {
			if (!canSegment[i - j]) {
				continue;
			}
			strncpy(subString, s+i-j, j);
			subString[j] = '\0';
			for (k = 0; k < wordDictSize; k++) {
				if (!strcmp(subString, wordDict[k])) {
					canSegment[i] = true;
					break;
				}
			}
		}
	}

	//for (i=0;i<=len;i++) {
	//	printf("%d ", canSegment[i]);
	//}
	
	return canSegment[len];
}
#else
bool indic(char *s, int i, int j, char** wordDict, int siz)
{
	char a[j-i+2];
	int k;

	memcpy(a, &s[i], j-i+1);
	a[j-i+1] = '\0';

	for (k=0; k<siz; k++) {
		if (!strcmp(a, wordDict[k]))
			return true;
	}
	return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
	int i,j;
	int len = strlen(s);
	bool dp[len];


	for (i=0; i<len; i++) {
		dp[i] = indic(s, 0, i, wordDict, wordDictSize);
		//printf(">> %d \n", dp[i]);
		for (j=i-1; j>=0; j--) {
			if (dp[i])
				break;
			if (dp[j] && indic(s, j+1, i, wordDict, wordDictSize)) {
				dp[i] = true;
			}
		}
	}
    
#if 0
	for (i=0; i<len; i++)
		printf("%d ", dp[i]);
#endif

	return dp[len-1];
}
#endif

int main(int argc, char *argv[])
{
	char *a="leet";
	char *b="code";
	char *p[2];

	p[0] = a;
	p[1] = b;


	printf("\n> %d\n", wordBreak("leetcode", p, 2));

	return 0;
}

