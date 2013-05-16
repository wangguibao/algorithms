/*
 * spiral_print_matrix.c
 * Print matrix spirally
 * example:
 *  1  2  3  4  5
 *  6  7  8  9 10
 * 11 12 13 14 15
 * 16 17 18 19 20
 * 21 22 23 24 25
 *
 * Output: 1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13
 */
#include <stdio.h>
#define MAX_ROW 16
#define MAX_COL 16

int matrix[MAX_ROW + 1][MAX_COL + 1];

/**
 * spiral_print_matrix
 *
 * Spirally print a matrix. Init call with spiral_print_matrix(1, 1, cols, rows)
 *
 * @param row_begin begin row in the global variable matrix
 * @param col_begin begin col in the global variable matrix
 * @param width     matrix width
 * @param height    matrix height
 */
void spiral_print_matrix(int row_begin, int col_begin, int width, int height)
{
    int row_end = row_begin + height - 1;
    int col_end = col_begin + width - 1;
    int i;
    int j;

    if (width < 1 || height < 1) {
        return;
    }

    if (width == 1) {
        for (j = row_begin; j <= row_end; j++) {
            printf("%d ", matrix[j][col_begin]);
        }
        return;
    }

    if (height == 1) {
        for (i = col_begin; i <= col_end; i++) {
            printf("%d ", matrix[row_begin][i]);
        }

        return;
    }

    for (i = col_begin; i <= col_end; i++) {
        printf("%d ", matrix[row_begin][i]);
    }

    for (j = row_begin + 1; j <= row_end; j++) {
        printf("%d ", matrix[j][col_end]);
    }

    for (i = col_end - 1; i >= col_begin; i--) {
        printf("%d ", matrix[row_end][i]);
    }

    for (j = row_end - 1; j > row_begin; j--) {
        printf("%d ", matrix[j][col_begin]);
    }

    spiral_print_matrix(row_begin + 1, col_begin + 1, width - 2, height - 2);
}

int main()
{
    int rows;
    int cols;
    int i;
    int j;

    printf("Matrix row (max %d): ", MAX_ROW);
    scanf("%d", &rows);
    printf("Maxtrix col (max %d): ", MAX_COL);
    scanf("%d", &cols);

    printf("Matrix data: %d rows X %d cols:\n", rows, cols);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    spiral_print_matrix(1, 1, cols, rows);

    return 0;
}
