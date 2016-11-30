#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version){
	if (version >= 1702766719)
		return true;

	return false;
}

int firstBadVersion(int n) {
    long long l=1, h=n, m=n/2;
    
    if (n <= 1)
        return n;
    
    while (l < h) {
        if (!isBadVersion(m) && isBadVersion(m+1))
            return m+1;
        
        if (isBadVersion(m)) { 
            h = m;
        } else { 
            l = m;
        }
        m = (l+h)/2;
		//printf("%d \n", m);
    }
    
    
    return m;
}

//2126753390 versions
//1702766719 is the first bad version.
int main(int argc, char *argv[])
{
	printf("> %d\n", firstBadVersion(2126753390));

	return 0;
}

