/**
 * @file sieve_of_eratosthenes.c
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @brief Find all prime numbers within a given range, using Sieve of Eratosthenes
 *
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
#include <stdio.h>
#include <limits.h>

#define MAX_ELE 1024

void sieve_of_eratosthenes(int n)
{
    int a[MAX_ELE + 1] = {0};
    int i = 0;
    int j = 0;
    if (n > MAX_ELE) {
        printf("Out of range (%u)\n", MAX_ELE);
        return;
    }

    for (i = 0; i <= n; ++i) {
        a[i] = i;
    }

    i = 2;
    while (i * i <= n) {
        for (j = i * i; j <= n; j += i) {
            a[j] = 0;
        }

        ++i;
        for (; i * i <= n; ++i) {
            if (a[i] != 0) {
                break;
            }
        }
    }

    for (i = 2; i <= n; ++i) {
        if (a[i] != 0) {
            printf("%u ", a[i]);
        }
    }
    printf("\n");
}

int main()
{
    int n = 0;
    int ret = 0;
    printf("Integer range in which to compute all prime numbers (max %u): ", MAX_ELE);

    ret = scanf("%u", &n);
    if (ret != 1 || n <= 1 || n > MAX_ELE) {
        printf("Invalid range %u\n", n);
        return -1;
    }

    sieve_of_eratosthenes(n);
    return 0;
}
