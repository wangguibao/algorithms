/*
 * in_situ_permutation.c - the array data[0, N-1] is to be rearranged in place
 * as directed by the index array a[0, N-1]
 *
 * Another implementation of Program 6.14, Algorithms in C, 3e, by R.Sedgewick
 */
#include <stdio.h>

#define ELE_NUM 16 /* Number of elements to be rearranged */

/**
 * in_situ_permutation
 * In place rearrangement of data array, as directed by index array a
 *
 * For each value of i, we save the value of data[i] and initialize an index
 * variable k to i. Now, think of a hole in data[i], and seek an element to fill
 * the hole. That element is data[a[k]] - in other words, the assignment
 * data[k] = data[a[k]] moves the hole to a[k]. Now the hole is at data[a[k]],
 * so we set k to a[k].Iterating, eventaually we get to a situation where the
 * hole needs to be filled by data[i] which we have saved. When we move an
 * element into position we update the index array to so indicate.
 */
void in_situ_permutation(int *data, int *a, int n)
{
    int i;
    int k;
    int current_index;
    int temp;
    
    for (i = 0; i < n; i++) {
        temp = data[i];
        for (current_index = i; a[current_index] != i;) {
            data[current_index] = data[a[current_index]];
            k = current_index;
            current_index = a[current_index];
            a[k] = k;
        }
        data[current_index] = temp;
        a[current_index] = current_index;
    }
    return;
}

int main()
{
    int data[ELE_NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int a[ELE_NUM] =    {3, 8, 4, 14, 6, 9, 15, 10, 12, 2, 0, 1, 5, 7, 13, 11};
    int i;

    printf("data before sort: ");
    for (i = 0; i < ELE_NUM; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("indice array   : ");
    for (i = 0; i < ELE_NUM; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    in_situ_permutation(data, a, ELE_NUM);

    printf("data after sort: ");
    for (i = 0; i < ELE_NUM; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}
