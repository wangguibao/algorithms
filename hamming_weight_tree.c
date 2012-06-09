/**
 * hamming_weight_tree.c - Calculates number of 1's in the binary representation
 * of a 32bit integer, using the tree method, , first proposed in HAKMEM:
 * http://dspace.mit.edu/bitstream/handle/1721.1/6086/AIM-239.pdf?sequence=2
 */
#include <stdio.h>

/**
 * Calculates number of 1's in the binary representation of a integer,
 * using the tree method
 * @parameter n the number to inspect
 * @return number of 1's in the binary representation of n
 */
int hamming_weight_tree(int n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

    return n;
}

int main()
{
    int n;

    while (scanf("%d", &n) && n != -1) {
        printf("%d\n", hamming_weight_tree(n));
    }

    return 0;
}
