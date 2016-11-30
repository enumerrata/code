#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


struct discnt {
	int dist;
	int cnt;
};

int count(struct discnt *d, int *len)
{
	int sum = 0;
	int i;

	for (i=0; i<*len; i++) {
		sum += d[i].cnt * (d[i].cnt - 1);
	}
	return sum;
}


int add(struct discnt *d, int *len, int d1)
{
	int i;
	for (i=0; i<*len; i++) {
		if (d[i].dist == d1) {
			d[i].cnt++;
			return;
		}
	}

	d[*len].dist = d1;
	d[*len].cnt = 1;
	*len += 1;

}

// should use map
int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize) {
    int i,j,k;
    int *prow;
    int d1;
	struct discnt disc[500];
	int len = 0;
	int sum = 0;
    
    for (i=0; i<pointsRowSize; i++) {
		len = 0;
        for (j=0; j<pointsRowSize; j++)  {
			if (j == i) continue; 
            d1 =  (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
            d1 += (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
			add(disc, &len, d1);
        }
		sum += count(disc, &len);
    }
        
    return sum;
}

int main(int argc, char *argv[])
{
	int a[] = {0,0 };
	int b[] = {1,0 };
	int c[] = {2,0 };
	int *d[] = {a,b,c};

	printf("> %d \n", numberOfBoomerangs(d, 3, 2));

	return 0;
}

