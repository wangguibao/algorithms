/*
 * min_heap_based_k_largest_elements.c
 * Find k largest elements in a random array, using min-heap - first construct
 * min-heap of k elements, then perform N - k replace the minimum operations
 */
#include <stdio.h>

#define MAX_ELE 16  /* Max number of elements */


/**
 * fix-up on array a, for element a[i], with last element at a[n]
 * @param   a   the array. Elements begin from a[1]
 * @param   i   the element to be adjusted
 * @return N/A
 */
void fix_up(int *a, int i)
{
    int j;
    int tmp;

    while (i > 0) {
        j = i / 2;
        if (a[i] >= a[j]) {
            break;
        }
        tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        i = j;
    }

    return;
}

/**
 * fix-down on array a, for element a[i], with last element at a[n]
 * @param   a   the array. Elements begin from a[1]
 * @param   i   the element to be adjusted
 * @param   n   last element in array
 * @return N/A
 */
void fix_down(int *a, int i, int n)
{
    int j;
    int tmp;

    while (2 * i <= n) {
        j = 2 * i;

        if (j < n && a[j] > a[j + 1]) {
            j = j + 1;
        }

        if (a[i] <= a[j]) {
            break;
        }

        tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        i = j;
    }

    return;
}

/**
 * find k largest elements in a random array, using min-heap
 * @param   a the array. Elements begin from a[1]
 * @param   n number of elements in array
 * @param   k number of largest elements to inspect
 * @return N/A
 */
void k_large(int *a, int n, int k)
{
    int i;

    /* Construct min-heap of k elements */
    for (i = k / 2; i >= 1; i--) {
        fix_down(a, i, k);
    }

    for (i = k + 1; i <= n; i++) {
        /* insert */
        a[k + 1] = a[i];
        fix_up(a, k + 1);

        /* delete minimum */
        a[1] = a[k + 1];
        fix_down(a, 1, k);
    }

    return;
}

int main()
{
    int k;
    int n;
    int i;
    int a[MAX_ELE + 1];

    printf("Number of elements (max %d) and k:", MAX_ELE);
    scanf("%d %d", &n, &k);

    printf("Elements:");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    k_large(a, n, k);

    printf("%d largest elements: ", k);
    for (i = 1; i <= k; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
