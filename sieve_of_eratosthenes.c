/**
 * @file sieve_of_eratosthenes.c
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @brief Find all prime numbers within a given range, using Sieve of Eratosthenes
 *
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
#define MAX_ELE 1001
int main()
{
    int prime[MAX_ELE + 1] = {1,};
    int i = 0;
    int j = 0;

    for (i = 0; i <= MAX_ELE; ++i) {
        prime[i] = 1;
    }

    i = 2;
    for (i = 2; i * i <= MAX_ELE;) {
        if (prime[i] == 1) {
            for (j = i * i; j <= MAX_ELE; j += i) {
                prime[j] = 0;
            }
        }

        ++i;
        while (i * i <= MAX_ELE) {
            if (prime[i] == 1) {
                break;
            }
            ++i;
        }
    }

    for (i = 2; i <= MAX_ELE; ++i) {
        if (prime[i] == 1) {
            printf("%u ", i);
        }
    }
    printf("\n");
    return 0;
}
