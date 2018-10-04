/*
 * longest-plateau.c
 * Given an array of integers, compose a program that finds the length and
 * location of the longest contiguous sequence of equal values where the values
 * of the elements just before and just after this sequence are smaller.
 */
#include <stdio.h>
#include <limits.h>
#define MAX_ELE 32

void max_equal_value_subarray(int *x, int begin, int end)
{
    int i = begin;
    int j = 0;
    int cur_start = 0;
    int cur_len = 0;
    int len = 0;

    for (; i < end; ) {
        j = i + 1;

        while (j < end && x[j] == x[i]) {
            ++j;
        }

        if (x[i - 1] > x[i] || x[j] > x[i]) {
            i = j;
            continue;
        }
        len = j - i;
        if (cur_len < len) {
            cur_len = len;
            cur_start = i;
        }
        i = j;
    }

    printf("start = %u, len = %u\n", cur_start, cur_len);

    return;
}

int main()
{
    int x[MAX_ELE + 2];

    printf("Please input maximum %d integers, end with ^D:\n", MAX_ELE);
    int n = 1;
    int ret = 0;
    x[0] = INT_MIN;
    while ((ret = scanf("%d", &x[n])) == 1 && n < MAX_ELE) {
        ++n;
    }
    x[n] = INT_MIN;

    max_equal_value_subarray(x, 1, n);

    return 0;
}
