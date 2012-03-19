/*
 * longest_mono_incr_seq.c - Longest monotonically increasing subsequence
 * problem
 */
#include <stdio.h>

#define MAX_ELE 16

/*
 * Returns the longest monotonically increasing subsequence
 * Integers in array a should begin with a[1] and end with a[len]
 */
int lmis(int *a, int len)
{
    int b[MAX_ELE + 1];     /* length of lmis up to b[i] */
    int i;
    int j;
    int max;

    b[0] = 0;
    for (i = 1; i <= len; i++) {
        b[i] = 1;
    }

    for (i = 1; i <= len; i++) {
        for (j = 1; j <= i; j++) {
            if (a[j] < a[i] && b[j] + 1 > b[i]) {
                b[i] = b[j] + 1;
            }
        }
    }

    max = b[1];
    for (i = 2; i <= len; i++) {
        if (max < b[i]) {
            max = b[i];
        }
    }

    return max;
}

int main()
{
    int a[MAX_ELE + 1];
    int len = 0;

    printf("Input at most 16 integers, end with 0:\n");

    while (scanf("%d", &a[len + 1]) && a[len + 1] != 0) {
        len++;
    }

    printf("%d\n", lmis(a, len));

    return 0;
}
