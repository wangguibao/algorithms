/*
 * bitvector-using-bit-op.c
 * Implement set(), clear() and test() with bit operations, like AND, OR, or SHIFT
 */
#include <stdio.h>
#include <string.h>

#define BITS        1000
#define BITSPERWORD 32
#define SHIFT       5

int a[1 + BITS/BITSPERWORD];

#define set(i) a[(i) >> SHIFT] |= 1 << ((i) & (BITSPERWORD - 1))
#define clear(i) a[(i) >> SHIFT] &= ~(1 << ((i) & (BITSPERWORD - 1)))
#define test(i) a[(i) >> SHIFT] & (1 << ((i) & (BITSPERWORD - 1)))

void init()
{
    memset(a, 0, sizeof(a));
}

void print()
{
    int i;
    int j;
    for (i = 0; i < sizeof(a) / sizeof(int); i += 4) {
        for (j = 0; j < 4; j++) {
            printf("0x%08x ", a[i + j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int main()
{
    set(0);
    set(10);
    set(35);
    set(48);
    print();

    clear(10);
    print();

    printf("bit 0 %s\n", test(0) ? "set" : "not set");
    printf("bit 10 %s\n", test(10) ? "set" : "not set");
    printf("bit 35 %s\n", test(35) ? "set" : "not set");
    printf("bit 48 %s\n", test(48) ? "set" : "not set");
    return 0;
}

