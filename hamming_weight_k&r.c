/**
 * hamming_weight_k&r.c - Calculates number of 1's in a binary sequence
 */
#include <stdio.h>

/**
 * Calculates number of 1's in a binary sequence in K&R method, i.e.,
 * hw(n) = hw(n & (n - 1)) + 1
 * Ref: http://perso.citi.insa-lyon.fr/claurado/ham/overview.pdf
 * @parameter n The integer to inspect
 * @return number of 1's in the integer
 */
int hamming_weight_k_r(int n)
{
    if (n == 0) {
        return 0;
    }

    return 1 + hamming_weight_k_r(n & (n - 1));
}

int main()
{
    int n;

    while (scanf ("%d", &n) && n != -1) {
        printf("%d\n", hamming_weight_k_r(n));
    }

    return 0;
}
