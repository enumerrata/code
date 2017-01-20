#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool existHelper(char** board, int rsize, int csize, char* word, int x, int y, bool** visited) {
    if (*word == '\0') {
        return true;
    }
    if (x > 0 && board[x-1][y] == *word && !visited[x-1][y]) {
        visited[x-1][y] = true;
        if (existHelper(board, rsize, csize, word+1, x-1, y, visited)) {
            return true;
        }
        visited[x-1][y] = false;
    }
    if (y > 0 && board[x][y-1] == *word && !visited[x][y-1]) {
        visited[x][y-1] = true;
        if (existHelper(board, rsize, csize, word+1, x, y-1, visited)) {
            return true;
        }
        visited[x][y-1] = false;
    }
    if (x < rsize - 1 && board[x+1][y] == *word && !visited[x+1][y]) {
        visited[x+1][y] = true;
        if (existHelper(board, rsize, csize, word+1, x+1, y, visited)) {
            return true;
        }
        visited[x+1][y] = false;
    }
    if (y < csize - 1 && board[x][y+1] == *word && !visited[x][y+1]) {
        visited[x][y+1] = true;
        if (existHelper(board, rsize, csize, word+1, x, y+1, visited)) {
            return true;
        }
        visited[x][y+1] = false;
    }
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    bool **visited = malloc(sizeof(bool *) * boardRowSize);
	int i,j;

	for (i = 0; i < boardRowSize; i++) {
		visited[i] = malloc(sizeof(bool) * boardColSize);
		for (j=0; j < boardColSize; j++) {
			visited[i][j] = false;
		}
	}

    for (i = 0 ; i < boardRowSize ; i++) {
        for (j = 0 ; j < boardColSize ; j++) {
            if (board[i][j] == *word) {
                visited[i][j] = true;
                if (existHelper(board, boardRowSize, boardColSize, word+1, i, j, visited)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
    }
	return false;
}


int main(int argc, char *argv[])
{
  	char a[] = {'A','B','C','E'};
  	char b[] = {'S','F','C','S'};
  	char c[] = {'A','D','E','E'};
	char *p[] = {a,b,c};


	printf("> %d\n", exist(p, 3, 4, "SEE"));

	return 0;
}

