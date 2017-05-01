#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


char *add(char *a, int siza, char *b, int sizb)
{
	int siz = siza>sizb?siza+1:sizb+1;
	char *res;
	int i,j,c=0;

	res = malloc(siz+1);
	res[siz] = '\0';

    for (i=siza-1,j=sizb-1; i>=0||j>= 0||c>0; i--,j--) {
        int n1 = (i >= 0) ? a[i] - '0' : 0;
        int n2 = (j >= 0) ? b[j] - '0' : 0;
        int sum = n1 + n2 + c;

        res[--siz] = (sum % 10) + '0';
        c = sum / 10;
    }
	return &res[siz];
}

bool equals(char* num1, char* num2, int size) {
    int i;

    for (i=0; i<size && num1[i]==num2[i]; i++)
		;

    return i == size;
}

bool isAdditiveNumber(char* num) {
    int size = strlen(num), size1, size2;
    char* num1 = num;
    char* num2 = num + 1;
	printf("%s\n", num);

    while (num2 <= num + size/2) {
        size1 = num2 - num1;
        size2 = 1;
        while (size1 + size2 < size) {
            char* sum = add(num1, size1, num2, size2);
            int sumlen = strlen(sum);
            if (sumlen + size1 + size2 > size) {
                break;
            }
            if (equals(sum, num2+size2, sumlen)) {
                if (sumlen + size1 + size2 == size) {
                    return true;
                } else if (isAdditiveNumber(num2)) {
                    return true;
                }
            }
            if (size2 == 1 && *num2 == '0') {
                break;
            }
            size2++;
        }
        num2++;
    }
    return false;
}




int main(int argc, char *argv[])
{
	printf("> %d\n", isAdditiveNumber("112358"));

	return 0;
}



