#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int valid(char *l, char *t, int len)
{
	int i;

	//for (i=0; i<len; i++)
	//	printf("%c ", l[i]);
	//printf("\n");

	memset(t, 0, len+1);

	for (i=0; i<len; i++) {
		if (l[i] != '.') {
			if (t[l[i]-'0'] != 0) {
				return 0;
			} else {
				t[l[i]-'0']++;
			}
		}
	}
	return 1;	
}

void getcol(char *b, char *l, int n, int len)
{
	int i;

	for (i=0; i<len; i++) {
		*l++ = *(b+i*len+n);
	}
}

void getline_(char *b, char *l, int n, int len)
{
	int i;

	b = b+n*len;

	for (i=0; i<len; i++) {
		*l++ = *b++;
	}
}

void getrect(char *b, char *l, int r, int c, int len)
{
	int i,j;

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			*l++ = *(b+ (r+i)*len + c+j);
		}
	}
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	int row = boardRowSize;
	int col = boardColSize;
	char *line;
	char *tline;
	int i,j;
	char *b;

	line = malloc(boardRowSize+boardColSize);
	tline = malloc(boardRowSize+1);
	b = malloc(boardRowSize*boardColSize);

	for (i=0; i<boardRowSize; i++)
	    memcpy(b+i*col, *(board+i), col);

	for (i=0; i<boardRowSize; i++) {
		getline_(b, line, i, boardColSize);
		if (!valid(line, tline, boardColSize))
			return false;
	}
	
	for (i=0; i<boardColSize; i++) {
		getcol(b, line, i, boardRowSize);
		if (!valid(line, tline, boardRowSize))
			return false;
	}
	printf(">>\n");
	for (i=0; i<boardColSize; i+=3)
		for (j=0; j<boardColSize; j+=3) {
			getrect(b, line, i, j, boardRowSize);
			if (!valid(line, tline, boardRowSize))
				return false;

		}
	return true;
}

int main(int argc, char *argv[])
{
	char *p[9] = {
		"....5..1.",
		".4.3.....",
		".....3..1",
		"8......2.",
		"..2.7....",
		".15......",
		".....2...",
		".2.9.....",
		"..4......",
	};

	printf("%d\n", isValidSudoku(p, 9, 9));

	return 0;
}

