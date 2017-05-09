#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "../tree.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int min(int a, int b)
{
    return a>b?b:a;
}
int max(int a, int b)
{
    return a>b?a:b;
}

struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    int *siz = returnSize;
    struct Interval *res;
    int i=0, overlap=0;
    
    *siz = 0;
    res = malloc(sizeof(struct Interval)*(intervalsSize +1));
    while (i < intervalsSize) {
        if (newInterval.end < intervals[i].start)
            break;
        else if (newInterval.start > intervals[i].end) {
            
        } else {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            overlap++;
        }
        i++;
    }
    
    memcpy(res, intervals, sizeof(struct Interval) * (i - overlap));
    memcpy(&res[i-overlap+1], &intervals[i], sizeof(struct Interval) * (intervalsSize-i));

    res[i-overlap].start = newInterval.start;
    res[i-overlap].end = newInterval.end;

    *siz = intervalsSize -overlap+1;
    return res;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

