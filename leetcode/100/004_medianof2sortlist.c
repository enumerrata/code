#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#include "tree.h"


int findKth(int *A, int s1, int A_start, int *B, int s2, int B_start, int k)
{		
	if (A_start >= s1) {
		return B[B_start + k - 1];
	}
	if (B_start >= s2) {
		return A[A_start + k - 1];
	}

	if (k == 1) {
		return min(A[A_start], B[B_start]);
	}
	
	int A_key = A_start + k / 2 - 1 < s1
				? A[A_start + k / 2 - 1]
				: INT_MAX;
	int B_key = B_start + k / 2 - 1 < s2
				? B[B_start + k / 2 - 1]
				: INT_MAX; 
	
	if (A_key < B_key) {
		return findKth(A, s1, A_start + k / 2, B, s2, B_start, k - k / 2);
	} else {
		return findKth(A, s1, A_start, B, s2, B_start + k / 2, k - k / 2);
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int len = nums1Size + nums2Size;
    
	if (len % 2 == 1) {
		return findKth(nums1, nums1Size, 0, nums2, nums2Size, 0, len / 2 + 1);
	}

	return (findKth(nums1, nums1Size, 0, nums2, nums2Size, 0, len / 2) + 
		findKth(nums1, nums1Size, 0, nums2, nums2Size, 0, len / 2 + 1)) / 2.0;
}

int main(int argc, char *argv[])
{
	int a[] = {1,2,3};
	int b[] = {4,5,6};

	printf("> %f\n", findMedianSortedArrays(a, 3, b,3));

	return 0;
}


/*
public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        int len = A.length + B.length;
        if (len % 2 == 1) {
            return findKth(A, 0, B, 0, len / 2 + 1);
        }
        return (
            findKth(A, 0, B, 0, len / 2) + findKth(A, 0, B, 0, len / 2 + 1)
        ) / 2.0;
    }

    // find kth number of two sorted array
    public static int findKth(int[] A, int A_start,
                              int[] B, int B_start,
                              int k){		
		if (A_start >= A.length) {
			return B[B_start + k - 1];
		}
		if (B_start >= B.length) {
			return A[A_start + k - 1];
		}

		if (k == 1) {
			return Math.min(A[A_start], B[B_start]);
		}
		
		int A_key = A_start + k / 2 - 1 < A.length
		            ? A[A_start + k / 2 - 1]
		            : Integer.MAX_VALUE;
		int B_key = B_start + k / 2 - 1 < B.length
		            ? B[B_start + k / 2 - 1]
		            : Integer.MAX_VALUE; 
		
		if (A_key < B_key) {
			return findKth(A, A_start + k / 2, B, B_start, k - k / 2);
		} else {
			return findKth(A, A_start, B, B_start + k / 2, k - k / 2);
		}
	}
}
*/
