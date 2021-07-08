/**
 * @file transpose.c
 * @author wangguibao(wang_guibao@163.com)
 * @date 2021/07/08 18:04:27
 * @brief 2-D Matrix transposition
 *
 **/

#include <iostream>

int** transpose(int** a, int m, int n)
{
    int** dst = new int*[n];
    for (int i = 0; i < n; ++i) {
        dst[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dst[i][j] = a[j][i];
        }
    }

    return dst;
}

int main()
{
    std::cout << "Input array dimensions (M N):" << std::endl;

    int m = 0;
    int n = 0;

    std::cin >> m;
    std::cin >> n;

    if (m * n <= 0) {
        std::cout << "Dimension error" << std::endl;
        return -1;
    }

    std::cout << "Input " << m << "x" << n << " elements:" << std::endl;
    int** array = new int*[m];
    for (int i = 0; i < m; ++i) {
        array[i] = new int[n];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> array[i][j];
        }
    }

    std::cout << "Input array:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << array[i][0];

        for (int j = 1; j < n; ++j) {
            std::cout << " " << array[i][j];
        }

        std::cout << std::endl;
    }

    int** dst = transpose(array, m, n);

    std::cout << "Output array:" << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << dst[i][0];
        for (int j = 1; j < m; ++j) {
            std::cout << " " << dst[i][j];
        }

        std::cout << std::endl;
    }

    // Release memory
    for (int i = 0; i < n; ++i) {
        delete[] dst[i];
    }

    delete[] dst;

    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
