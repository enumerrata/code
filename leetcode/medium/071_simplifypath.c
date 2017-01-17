#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void copy(char *s, int len, char **p)
{
	*p = malloc(len+1);
	memcpy(*p, s, len);
	(*p)[len] = '\0';
}

char* simplifyPath(char* path) {
    char *p = malloc(strlen(path));
	char **l = malloc(sizeof(char *) * (strlen(path)+1));
	int len = 0;
	char *t;
	char *end = path + strlen(path);
	char *q = p;
    
    while (*path) {
		t = strchr(path, '/');
		if (path == t) {
			path++;
			continue;
		}
		//printf(">> %s \n", path);
		if (t)
			copy(path, t-path, &l[len]);
		else {
			copy(path, strlen(path), &l[len]);
		}
		//printf("%s\n", l[len]);
			
		if (!strcmp(l[len], "..")) {
			len--;
		} else if (strcmp(l[len], ".")){
			len++;
		}
		
		if (len < 0)
			len = 0;
		
		path = t;
		if (!t)
			break;
    }
	//printf("len %d\n", len);

	int i;
    if (len <= 0) {
        sprintf(p, "/");
    } else {
    	for (i=0; i<len; i++) {
    		p+=sprintf(p, "/%s", l[i]);
    	}
            
    }
	return q;
}

int main(int argc, char *argv[])
{
	//char *p = "/Zfq/pSEY///cSJ/CI/vJ/j//";
	char *p = "/./yPvI/./X/../cCwm/../../.";

	printf("> %s\n", simplifyPath(p));

	return 0;
}

