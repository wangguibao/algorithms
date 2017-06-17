/**
 * @file diagonal-traversal-2d-matrix.c
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @brief Traversal a 2D array diagonally, e.g.:
 *
 *   1  2  3  4            1
 *   5  6  7  8            5  2
 *   9 10 11 12            9  6  3
 *  13 14 15 16     =>    13 10  7 4
 *  17 18 19 20           17 14 11 8
 *                        18 15 12
 *                        19 16
 *                        20
 */
#include <stdio.h>

void print_2d_matrix_diagonal(int total_row, int total_col, int matrix[total_row][total_col])
{
    int limit = total_row + total_col - 1;
    int row = 0;
    int col = 0;
    int meter = 0;
    if (limit <= 1) {
        return;
    }

    int start_row = 0;
    for (meter = 0; meter < limit; ++meter) {
        start_row = meter >= total_row - 1 ? total_row - 1 : meter;
        for (row = start_row, col = meter - start_row;
                row + col <= meter && row >= 0 && col < total_col;
                --row, ++col) {
            printf("%2d ", matrix[row][col]);
        }
        printf("\n");
    }

    return;
}
int main()
{
    int matrix54[][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 29, 20}
    };

    int total_row = sizeof(matrix54) / sizeof(matrix54[0]);
    int total_col = sizeof(matrix54[0]) / sizeof(matrix54[0][0]);

    print_2d_matrix_diagonal(total_row, total_col, matrix54);

    int matrix45[][5] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };
    total_row = sizeof(matrix45) / sizeof(matrix45[0]);
    total_col = sizeof(matrix45[0]) / sizeof(matrix45[0][0]);
    print_2d_matrix_diagonal(total_row, total_col, matrix45);

    return 0;
}
