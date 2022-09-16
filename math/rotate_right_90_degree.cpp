/**
 * @file rotate_right_90_degree.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2022/09/16 14:12:17
 * @brief
 *
 **/

#include <iostream>

int* rotate_right_90(int* a, int m, int n)
{
    int tmp = 0;
    int* b = new int[m * n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i * m + j] = a[(m - 1 - j) * n + i];
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

    int* dst = rotate_right_90(array, m, n);

    std::cout << "Output array:" << std::endl;

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
