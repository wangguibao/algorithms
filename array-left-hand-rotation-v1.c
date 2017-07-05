/**
 * array-left-hand-rotation-v1.c
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @brief Left-hand rotation of an integer array, using O(1) extra space and
 *       O(n) running time.
 *
 * This is an implementation of Question 2 of Ch 2, Programming Pearls 2e.
 */
#include <stdio.h>

#define MAX_ELE 16

void array_left_hand_rotation(int *ele, size_t size, int rotation_count)
{
    int offset = 0;
    int temp = 0;
    int pos = 0;
    if (rotation_count % size == 0) {
        return;
    }

    rotation_count %= size;

    for (; offset < rotation_count; ++offset) {
        temp = ele[offset];
        pos = offset;
        while (1) {
            if (((pos + rotation_count) % size) == offset) {
                ele[pos % size] = temp;
                break;
            }
            else {
                ele[pos % size] = ele[(pos + rotation_count) % size];
                pos += rotation_count;
            }
        };

        if ((size % rotation_count) != 0) {
            break;
        }
    }
}

int main()
{
    int n = 0;
    int rotation_count = 0;
    int ele[MAX_ELE] = {0, };
    int ret = 0;
    int i = 0;

    fprintf(stdout, "Number of elements (max %d): ", MAX_ELE);
    ret = scanf("%d", &n);
    if (ret != 1) {
        fprintf(stderr, "Number of elements not specified\n");
        return -1;
    }
    else if (n > MAX_ELE || n <= 0) {
        fprintf(stderr, "Number of elements not valid\n");
        return -1;
    }

    fprintf(stdout, "%d integers: ", n);
    for (i = 0; i < n; ++i) {
        ret = scanf("%d", &ele[i]);
        if (ret != 1) {
            fprintf(stderr, "Element %d error\n", i);
            return -1;
        }
    }

    fprintf(stdout, "Rotation count: ");
    ret = scanf("%u", &rotation_count);
    if (ret != 1) {
        fprintf(stderr, "Rotation count not specified\n");
        return -1;
    }

    array_left_hand_rotation(ele, n, rotation_count);
    for (i = 0; i < n; ++i) {
        fprintf(stdout, "%d ", ele[i]);
    }
    fprintf(stdout, "\n");

    return 0;
}
