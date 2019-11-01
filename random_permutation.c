/**
 * random_permutation.c
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @brief Generate a random permutation for number 1-N, using Fisher-Yates Shuffle algorithm
 * https://en.wikipedia.org/wiki/Fisher¨CYates_shuffl
 *
 * Note this algorithm is a generalization of the problem:
 * Pick k random numbers from 1-N in linear time
 *
 * Because once a permutation for 1-N is finished, one can immediately pick first K numbers,
 * hence the solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANGE 16

void permutation(int n)
{
    srandom(time(NULL));
    int a[MAX_RANGE] = {0};
    int i = 0;
    long long pos = 0;
    int tmp = 0;

    for (i = 1; i <= MAX_RANGE; ++i) {
        a[i] = i;
    }

    printf("RAND_MAX=%d\n", RAND_MAX);
    for (i = n; i >= 1; --i) {
        pos = random();
        pos = 1 + (double)(pos * i) / ((long long)RAND_MAX + 1);
        printf("i = %d, pos=%lld\n", i, pos);
        tmp = a[i];
        a[i] = a[pos];
        a[pos] = tmp;
    }

    for (i = 1; i <= n; ++i) {
        printf("%u ", a[i]);
    }

    printf("\n");
    return;
}

int main()
{
    int n = 0;
    printf("Range N (1-%u): ", MAX_RANGE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_RANGE) {
        printf("Out of range\n");
        return 0;
    }

    permutation(n);
    return 0;
}
