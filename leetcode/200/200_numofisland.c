#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"


void visit(int **map, int r, int c, int rmax, int cmax)
{
	map[r][c] = 0;

    if (r < rmax - 1 && map[r+1][c] == 1) {
        visit(map, r+1, c, rmax, cmax); // to bottom
    }
    if (c < cmax - 1 && map[r][c+1] == 1) {
        visit(map, r, c+1, rmax, cmax); // to right
    }
    if (r > 0 && map[r-1][c] == 1) {
        visit(map, r-1, c, rmax, cmax); // to top
    }
    if (c > 0 && map[r][c-1] == 1) {
        visit(map, r, c-1, rmax, cmax); // to left
    }
}


int numIslands(char** grid, int gridRowSize, int gridColSize) {
	int **map;
	int i,j;
	int count = 0;

	map = malloc(sizeof(int *) * gridRowSize);
	for (i=0; i<gridRowSize; i++) {
		map[i] = malloc(sizeof(int) * gridColSize);
		for (j=0; j<gridColSize; j++) {
			map[i][j] = grid[i][j] - '0';
		}
	}

    for (i=0 ; i<gridRowSize ; i++) {
        for (j=0 ; j<gridColSize ; j++) {
            if (map[i][j] == 1) {
                count++;
                visit(map, i, j, gridRowSize, gridColSize);
            }
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

