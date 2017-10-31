/**
 * extended-euclidean-algorithm.c
 *
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @brief Calculates Bezout's coefficents, along with greatest common divisor,
 *        of two positive integers, using extended Euclidean Algorithm.
 *        https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
 *        https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
 *
 *        Note this algorithm relates to Chinese Remainder Theorem
 */
#include <stdio.h>

int s0 = 1;
int s1 = 0;
int t0 = 0;
int t1 = 1;

int extended_euclidean(int a, int b)
{
    int r = 0;
    int q = 0;
    int tmp = 0;

    if (a == 0 || b == 0) {
        return 0;
    }

    if (a < b) {
        return extended_euclidean(b, a);
    }

    while (b != 0) {
        r = a % b;
        q = a / b;
        a = b;
        b = r;

        tmp = s0 - q * s1;
        s0 = s1;
        s1 = tmp;

        tmp = t0 - q * t1;
        t0 = t1;
        t1 = tmp;
    }

    return a;
}

int main()
{
    int a = 0;
    int b = 0;

    fprintf(stdout, "Two integers: ");
    scanf("%d %d", &a, &b);

    if (a < 0 || b < 0) {
        fprintf(stderr, "Negative numbers not acceptable\n");
        return -1;
    }

    extended_euclidean(a, b);
    fprintf(stdout, "Greatest common divisor is: %u, with s=%d t=%d",
            extended_euclidean(a, b),
            a >= b ? s1 : t1,
            a >= b ? t1 : s1);

    return 0;
}
