/**
 * @file k_min_sums_in_two_sorted_array.c
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @brief Find k pairs with smallest sums in two sorted arrays, such that one
 *        element picked from first array, another one from second array.
 */
#include <stdio.h>
#include <limits.h>

#define MAX_ELE 16

void k_min_sums_in_two_sorted_array(int *array1, int n1, int *array2, int n2, int k)
{
    int min_sum = INT_MAX;
    int min_index = -1;
    int i = 0;

    if (array1 == NULL || array2 == NULL) {
            return;
    }
    if (k > n1 * n2) {
        return;
    }

    int index2[MAX_ELE] = {0};

    while (k > 0) {
        min_sum = INT_MAX;
        min_index = -1;

        for (i = 0; i < n1; ++i) {
            if (index2[i] < n2 && array1[i] + array2[index2[i]] < min_sum) {
                min_sum = array1[i] + array2[index2[i]];
                min_index = i;
            }
        }

        printf("(%d, %d) ", array1[min_index], array2[index2[min_index]]);
        ++index2[min_index];
        --k;
    }
    printf("\n");
}

int main()
{
    int n1 = 0;
    int n2 = 0;
    int k = 0;
    int ret = 0;
    int i = 0;
    int array1[MAX_ELE] = {0, };
    int array2[MAX_ELE] = {0, };

    fprintf(stdout, "Number of elements in array1 (max %d): ", MAX_ELE);
    ret = scanf("%u", &n1);
    if (ret != 1) {
        fprintf(stderr, "Invalid number\n");
        return -1;
    }
    for (i = 0; i < n1; ++i) {
        scanf("%d", &array1[i]);
    }


    fprintf(stdout, "Number of elements in array2 (max %d): ", MAX_ELE);
    ret = scanf("%u", &n2);
    if (ret != 1) {
        fprintf(stderr, "Invalid number\n");
        return -1;
    }
    for (i = 0; i < n2; ++i) {
        scanf("%d", &array2[i]);
    }

    fprintf(stdout, "Number of minimum sums: ");
    ret = scanf("%u", &k);
    if (ret != 1 || k > n1 * n2) {
        fprintf(stderr, "Invalid number\n");
        return -1;
    }

    k_min_sums_in_two_sorted_array(array1, n1, array2, n2, k);

    return 0;
}
