/*
 * count_bits.c
 * Count number of 1-bits in each of a sequence of consecutive integers, in
 * O(N) complexity.
 *
 * The idea is to use previously calculated results
 *
 */
#include <stdio.h>
#include <math.h>
#define N 50

int main()
{
    int bits[N] = {0, 1};
    int pow[N] = {1, 2};
    int i = 0;

    for (i = 2; i < N; ++i) {
        if (pow[i-1] * 2 == i) {
            pow[i] = i;
        }
        else {
            pow[i] = pow[i -1];
        }
    }

    for (i = 2; i < N; ++i) {
        bits[i] = 1 + bits[i - pow[i]];
    }

    for (i = 0; i < N; ++i) {
        fprintf(stdout, "bits[%u] = %u, pow[%u] = %u\n", i, bits[i], i, pow[i]);
    }

    return 0;
}

