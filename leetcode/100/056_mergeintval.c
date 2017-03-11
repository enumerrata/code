#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
};

static int cmp(const void *p1, const void *p2) 
{
	struct Interval *q1 = (struct interval *)p1;
	struct Interval *q2 = (struct interval *)p2;

	if (q1->start > q2->start)
		return 1;
	else if (q1->start < q2->start)
		return -1;
	else
		return 0;
}

int max(int a, int b)
{
	return a>b ? a:b;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
	struct Interval *p = malloc(sizeof(struct Interval) * 1000);
	struct Interval *l = intervals;
    int i;

    if (intervalsSize <= 1) {
        (* returnSize) = intervalsSize;
        return l;
    }

	qsort (l, intervalsSize, sizeof(struct Interval), cmp);

    (* returnSize) = 0;
	p[0].start = l[0].start;
	p[0].end = l[0].end;
    for (i = 1 ; i < intervalsSize ; i++) {
        if (l[i].start > p[(* returnSize)].end) {
            (* returnSize)++;
            p[(* returnSize)].start = l[i].start;
            p[(* returnSize)].end = l[i].end;
        } else {
            p[(* returnSize)].end = max(p[(* returnSize)].end, l[i].end);
        }
    }
    (* returnSize)++;
   	return p; 
}

int main(int argc, char *argv[])
{
	struct Interval p[4]; 

	p[0].start = 1;
	p[0].end = 4;
	p[1].start = 1;
	p[1].end = 5;
	p[2].start = 8;
	p[2].end = 10;
	p[3].start = 15;
	p[3].end = 18;

	struct Interval *pp;
	int siz;
	int i;

	pp = merge(p, 2, &siz);
	for (i=0; i<siz; i++) {
		printf("> %d %d\n", pp[i].start, pp[i].end);
	}

	return 0;
}

