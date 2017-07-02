/**
 * median-of-two-sorted-arrays.c
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @breif Find median of two sorted arrays whose lenghs not necessarily equal
 *
 * This is a specialize case of finding the k-th element in the union of two
 * sorted arrays: assuming length of each arrays is m, n respectively, the
 * problem is to find (m + n) / 2 - th element.
 *
 * This is an implementation of the answer on stackflow by @Kaidul Islam
 * https://stackoverflow.com/questions/44274747/finding-median-in-merged-array-of-two-sorted-arrays/44275683#44275683
 */
#include <stdio.h>
#include <limits.h>
#include <assert.h>

#define MAX_ELE 16

int find_kth_ele_of_two_sorted_arrays(int *arr1,
                                    size_t arr1_len,
                                    size_t arr1_start,
                                    int *arr2,
                                    size_t arr2_len,
                                    size_t arr2_start,
                                    int k)
{
    printf("arr1_start=%lu arr1_len=%lu arr2_start=%lu arr2_len=%lu k=%d\n",
            arr1_start,
            arr1_len,
            arr2_start,
            arr2_len,
            k);
    assert(k <= arr1_len + arr2_len);
    if (arr1_len <= arr1_start) {
        return arr2[arr2_start + k - 1];
    }

    if (arr2_len <= arr2_start) {
        return arr1[arr1_start + k - 1];
    }
    if (k == 1) {
        return arr1[arr1_start] <= arr2[arr2_start]
            ? arr1[arr1_start]
            : arr2[arr2_start];
    }

    int arr1_value = arr1[arr1_len - 1];
    int arr1_k = arr1_len;
    if (k / 2 + arr1_start - 1 < arr1_len) {
        arr1_k = arr1_start + k / 2 - 1;
        arr1_value = arr1[arr1_k];
    }

    int arr2_k = arr2_len;
    int arr2_value = arr2[arr2_len - 1];
    if (k / 2 + arr2_start - 1 < arr2_len) {
        arr2_k = arr2_start + k / 2 - 1;
        arr2_value = arr2[arr2_k];
    }

    if (arr1_value < arr2_value) {
        return find_kth_ele_of_two_sorted_arrays(arr1,
                                                arr1_len,
                                                arr1_k + 1,
                                                arr2,
                                                arr2_len,
                                                arr2_start,
                                                k - k / 2);
    }
    else {
        return find_kth_ele_of_two_sorted_arrays(arr1,
                                                arr1_len,
                                                arr1_start,
                                                arr2,
                                                arr2_len,
                                                arr2_k + 1,
                                                k - k / 2);
    }
}

int median_of_two_sorted_arrays(int *arr1,
                                size_t arr1_len,
                                int *arr2,
                                size_t arr2_len)
{
    int total = arr1_len + arr2_len;

    if ((total & 0x1) == 0 ) {
        int left_pos = total / 2;
        int right_pos = total / 2 + 1;
        int left = find_kth_ele_of_two_sorted_arrays(arr1,
                                                    arr1_len,
                                                    0,
                                                    arr2,
                                                    arr2_len,
                                                    0,
                                                    left_pos);
        int right = find_kth_ele_of_two_sorted_arrays(arr1,
                                                    arr1_len,
                                                    0,
                                                    arr2,
                                                    arr2_len,
                                                    0,
                                                    right_pos);
        printf("left_pos=%u left=%d right_pos=%u right=%d median=%d\n",
                left_pos,
                left,
                right_pos,
                right,
                (left + right) / 2);
        return (left + right) / 2;
    }
    else {
        return find_kth_ele_of_two_sorted_arrays(arr1,
                                                arr1_len,
                                                0,
                                                arr2,
                                                arr2_len,
                                                0,
                                                (total >> 1) + 1);
    }
}

int main()
{
    int arr1[MAX_ELE] = {0, };
    int arr2[MAX_ELE] = {0, };
    int i = 0;
    int arr1_len = 0;
    int arr2_len = 0;
    int ret = 0;

    printf("Number of elements in first array (max %u): ", MAX_ELE);
    ret = scanf("%u", &arr1_len);
    if (ret != 1) {
        printf("Input invalid\n");
        return -1;
    }
    if (arr1_len > MAX_ELE) {
        printf("Number of elements out of range\n");
        return -1;
    }

    for (i = 0; i < arr1_len; ++i) {
        ret = scanf("%u", &arr1[i]);
        if (ret != 1) {
            printf("Input invalid in number %u\n", i);
            return -1;
        }
    }

    printf("Number of elements in second array (max %u): ", MAX_ELE);
    ret = scanf("%u", &arr2_len);
    if (ret != 1) {
        printf("Input invalid\n");
        return -1;
    }
    if (arr2_len > MAX_ELE) {
        printf("Number of elements out of range\n");
        return -1;
    }

    for (i = 0; i < arr2_len; ++i) {
        ret = scanf("%u", &arr2[i]);
        if (ret != 1) {
            printf("Input invalid in number %u\n", i);
            return -1;
        }
    }

    ret = median_of_two_sorted_arrays(arr1, arr1_len, arr2, arr2_len);
    printf("%d\n", ret);
    return 0;
}
