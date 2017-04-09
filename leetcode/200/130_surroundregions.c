#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


// Recursive method is not ok because it will cause stackoverflow

void push(int *row_index, int *col_index, int *queue_start, int *queue_end, int row, int col) {
    int i;
    for (i = *queue_start; i <= *queue_end; i++) {
        if ((row_index[i] == row) && (col_index[i] == col)) {
            return;
        }
    }
    *queue_end += 1;
    row_index[*queue_end] = row;
    col_index[*queue_end] = col;
}

void pop(int *row_index, int *col_index, int *queue_start, int *queue_end) {
    *queue_start += 1;
}

void bfs_change(char** b, int i, int j, int bRowSize, int bColSize, int *row_index, int *col_index, int *queue_start, int *queue_end) {
    push(row_index, col_index, queue_start, queue_end, i, j);
    while (*queue_start <= *queue_end) {
        if (0 <= row_index[*queue_start] - 1) {
            if ('O' == b[row_index[*queue_start] - 1][col_index[*queue_start]]) {
                push(row_index, col_index, queue_start, queue_end, row_index[*queue_start] - 1, col_index[*queue_start]);
            }
        }
        if (bRowSize - 1 >= row_index[*queue_start] + 1) {
            if ('O' == b[row_index[*queue_start] + 1][col_index[*queue_start]]) {
                push(row_index, col_index, queue_start, queue_end, row_index[*queue_start] + 1, col_index[*queue_start]);
            }
        }
        if (0 <= col_index[*queue_start] - 1) {
            if ('O' == b[row_index[*queue_start]][col_index[*queue_start] - 1]) {
                push(row_index, col_index, queue_start, queue_end, row_index[*queue_start], col_index[*queue_start] - 1);
            }
        }
        if (bColSize - 1 >= col_index[*queue_start] + 1) {
            if ('O' == b[row_index[*queue_start]][col_index[*queue_start] + 1]) {
                push(row_index, col_index, queue_start, queue_end, row_index[*queue_start], col_index[*queue_start] + 1);
            }
        }
        b[row_index[*queue_start]][col_index[*queue_start]] = 'E';
        pop(row_index, col_index, queue_start, queue_end);
    }
}

void solve(char** b, int bRowSize, int bColSize) {
    int i = 0;
    int j = 0;
    int npoint = bRowSize * bColSize;
    int *row_index;
    int *col_index;
    int queue_start = 0;
    int queue_end = -1;

    row_index = (int*)malloc(npoint * sizeof(int));
    col_index = (int*)malloc(npoint * sizeof(int));

    for (i = 0; i < bRowSize; i++) {
        if ('O' == b[i][0]) {
            bfs_change(b, i, 0, bRowSize, bColSize, row_index, col_index, &queue_start, &queue_end);
        }
        if ('O' == b[i][bColSize - 1]) {
            bfs_change(b, i, bColSize - 1, bRowSize, bColSize, row_index, col_index, &queue_start, &queue_end);
        }
    }
    for (j = 0; j < bColSize; j++) {
        if ('O' == b[0][j]) {
            bfs_change(b, 0, j, bRowSize, bColSize, row_index, col_index, &queue_start, &queue_end);
        }
        if ('O' == b[bRowSize - 1][j]) {
            bfs_change(b, bRowSize - 1, j, bRowSize, bColSize, row_index, col_index, &queue_start, &queue_end);
        }
    }
    for (i = 0; i < bRowSize; i++) {
        for (j = 0; j < bColSize; j++) {
            if ('O' == b[i][j]) {
                b[i][j] = 'X';
            }
            if ('E' == b[i][j]) {
                b[i][j] = 'O';
            }
        }
    }
}   


int main(int argc, char *argv[])
{
	char a[] = "XXXX";
	char b[] = "XOOX";
	char c[] = "XXOX";
	char d[] = "XOXX";
	char *p[4];

	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = d;

	solve(p, 4, 4);
	printf("%s\n", p[0]);
	printf("%s\n", p[1]);
	printf("%s\n", p[2]);
	printf("%s\n", p[3]);

	return 0;
}

