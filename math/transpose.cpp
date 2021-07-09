/**
 * @file transpose.c
 * @author wangguibao(wangguibao@baidu.com)
 * @date 2021/07/08 18:04:27
 * @brief Matrix transposition
 *
 **/

#include <iostream>

int* transpose(int* a, int m, int n)
{
    int tmp = 0;
    int* b = new int[m * n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i * m + j] = a[j * n + i];
        }
    }

    return b;
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
    int* array = new int[m * n];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> array[i * n + j];
        }
    }

    // Output input array
    std::cout << "Input array:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << array[i * n + 0];

        for (int j = 1; j < n; ++j) {
            std::cout << " " << array[i * n + j];
        }

        std::cout << std::endl;
    }

    // Transpose, returning a new array
    int*dst = transpose(array, m, n);

    std::cout << "Output array:" << std::endl;

    // Output transposed array
    for (int i = 0; i < n; ++i) {
        std::cout << dst[i * m + 0];
        for (int j = 1; j < m; ++j) {
            std::cout << " " << dst[i * m + j];
        }

        std::cout << std::endl;
    }

    delete[] array;
    delete[] dst;

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
