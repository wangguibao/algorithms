/*
 * Largest sum of all possible subarrays
 */

#include <stdio.h>

#define MAX_ELE 16

/*
 * lss - returns largest sum of all possible subarrays
 */
int lss(int *a, int n)
{
    int total = a[0];
    int sum = a[0];
    int b = 0;
    int i;

    for (i = 1; i < n; i++) {
        if (sum < 0) {
            sum = a[i];
            b = i;
        }
        else {
            sum += a[i];
        }

        if (total < sum) {
            total = sum;
        }
    }

    return total;
}

int main()
{
    int a[MAX_ELE];
    int num;
    int i = 0;

    printf("Input at most %d integers, end with 0:\n", MAX_ELE);
    while (scanf("%d", &num) && num != 0) {
        a[i] = num;
        i++;
    }

    printf("Largest sum of subarray is %d\n", lss(a, i));

    return 0;
}
