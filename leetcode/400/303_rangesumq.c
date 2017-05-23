#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#if 0
struct NumArray {
    int size;
    int *nums;
    
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    int *p = malloc(sizeof(int) * numsSize);
    struct NumArray *na = malloc(sizeof(struct NumArray));
    int i;
    
    na->nums = p;
    for (i=0; i<numsSize; i++) {
        na->nums[i] = nums[i];
    }
    na->size = numsSize;
    
    return na;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    int sum = 0;
    int k;
    
    for (k=i; k<=j; k++)
        sum += numArray->nums[k];
    return sum;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->nums);
    free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
#else
typedef struct {
    int *nums;
    int siz;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *p;
    int i;
    int sum=0;
    
    p = malloc(sizeof(NumArray));
    p->nums = malloc(sizeof(int) * (numsSize+1));
    
    p->nums[0] = 0;
    for (i=0; i<numsSize; i++) {
        sum += nums[i];
        p->nums[i+1] = sum;
    }
    p->siz = numsSize;
    return p;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    
    return obj->nums[j+1] - obj->nums[i];
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
#endif

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

