/*
 * insertion sort
 */
#include <stdio.h>
#define MAX_ELE 50

void insert_sort(int *a, int n) {
    int i = 0;
    int j = 0;
    if (a == NULL || n <= 1) {
        return;
    }

    for (i = 1; i < n; ++i) {
        int tmp = a[i];
        for (j = i - 1; j >= 0; --j) {
            if (a[j] > tmp) {
                a[j + 1] = a[j];
            }
            else {
                break;
            }
        }
        a[j + 1] = tmp;
    }

    return;
}

int main()
{
    int n;
    int a[MAX_ELE + 1];
    int i = 0;

    printf("Insert Sort\n");
    printf("Number of elements (max %u): ", MAX_ELE);
    scanf("%u", &n);
    for (; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    insert_sort(a, n);

    for (i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
