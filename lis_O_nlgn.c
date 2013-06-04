/*
 * lis_O_nlgn.c
 * O(nlgn) DP algorithm for Longest Increasing Subsequence problem
 *
 * http://stackoverflow.com/a/2631810/1513460
 * http://stackoverflow.com/a/7614385/1513460
 */
#include <stdio.h>
#include <limits.h>
#include <assert.h>

#define MAX_ELE     16  /* Max number of elements allowed */
#define MININFINITY INT_MIN

int a[MAX_ELE + 1];
int max[MAX_ELE + 1];   /* value of last element of LIS length i */
int idx[MAX_ELE + 1];   /* Index of last element of LIS length i */
int parent[MAX_ELE + 1];/* Parent of element in max[i] */

void inspect()
{
    int i;

    printf("max:    ");
    for (i = 0; i <= MAX_ELE; i++) {
        printf("%d ", max[i]);
    }
    printf("\nidx:    ");
    for (i = 0; i <= MAX_ELE; i++) {
        printf("%d ", idx[i]);
    }
    printf("\nparent: ");
    for (i = 0; i <= MAX_ELE; i++) {
        printf("%d ", parent[i]);
    }
    printf("\n");
    return;
}

/**
 * Find the ceiling element of n, e.g. smallest element that's larger than n,
 * in a sorted array a
 *
 * @param a         sorted array
 * @param length    length of m
 * @param n         element to find
 * @return index to the array of the found element, or -1 if not found
 */
int find_ceil(int *a, int length, int n)
{
    int begin = 0;
    int end = length - 1;
    int mid;

    while (begin <= end) {
        mid = begin + (end >> 2);
        if (a[mid - 1] < n && n < a[mid]) {
            return mid;
        }
        else if (a[mid] < n) {
            begin = mid + 1;
        }
        else if (n < a[mid - 1]) {
            end = mid - 1;
        }
    }

    return -1;
}

/**
 * Trace back along the parent[] and a[] arrays to construct the LIS
 * @param n 
 * @return N/A
 */
void trace_back(int index)
{
    if (parent[index] != -1) {
        trace_back(parent[index]);
    }
    printf("%d ", a[index]);
    return;
}

/**
 * O(nlgn) DP algorithm for longest increasing subsequence problem
 * Input elements are a[0] through a[n - 1]
 *
 * @param a array of integers
 * @param n number of integers in array a
 * @return N/A
 */
void lis_o_nlgn(int *a, int n)
{
    int i;
    int length;
    int pos;

    for (i = 0; i <= MAX_ELE; i++) {
        max[i] = MININFINITY;
        idx[i] = -1;
        parent[i] = -1;
    }

    length = 1;
    max[0] = a[0];
    idx[0] = 0;
    parent[0] = -1;

    for (i = 1; i < n; i++) {
        if (a[i] < max[0]) {
            max[0] = a[i];
            idx[0] = i;
            parent[i] = -1;
        }
        else if (a[i] > max[length - 1]) {
            length++;
            max[length - 1] = a[i];
            idx[length - 1] = i;
            parent[i] = idx[length - 1 - 1];
        }
        else {
            pos = find_ceil(max, length, a[i]);
            assert(pos != -1);
            max[pos] = a[i];
            idx[pos] = i;
            parent[i] = idx[pos - 1];
        }
    }

    inspect();
    trace_back(idx[length - 1]);
    return;
}

int main()
{
    int n;
    int i;

    printf("Longest increasing subsequence problem.\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    lis_o_nlgn(a, n);

    return 0;
}
