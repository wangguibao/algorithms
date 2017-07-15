/**
 * gcd.c
 *
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @brief Calculates greatest common divisor of two positive integers, using Euclidean Algorithm
 * https://en.wikipedia.org/wiki/Euclidean_algorithm
 *
 */
#include <stdio.h>

int gcd(int a, int b)
{
    int remainder = 0;
    if (a == 0 || b == 0) {
        return 0;
    }

    if (a < b) {
        return gcd(b, a);
    }

    remainder = a % b;
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }

    return b;
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

    fprintf(stdout, "Greatest common divisor is: %u", gcd(a, b));

    return 0;
}
