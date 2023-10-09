/*
 * matrix-multiply.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/07 19:45
 * @brief Implements matrix multiplication without optimization
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixMultiply(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B) {
    std::vector<std::vector<int>> resVec;

    int rowsA = A.size();
    int colsA = A[0].size();

    int rowsB = B.size();
    int colsB = B[0].size();

    if (colsA != rowsB) {
        return resVec;
    }

    for (int i = 0; i < rowsA; ++i) {
        std::vector<int> row;

        for (int j = 0; j < colsB; ++j) {
            int x = 0;
            for (int k = 0; k < colsA; ++k) {
                x += A[i][k] * B[k][j];
            }
            row.push_back(x);
        }

        resVec.push_back(row);
    }

    return resVec;
}

int main() {
    std::vector<std::vector<int>> A;

    A.push_back({1, 2, 3});
    A.push_back({3, 2, 2});
    A.push_back({2, 1, 2});

    std::vector<std::vector<int>> B;
    B.push_back({2, 2});
    B.push_back({3, 1});
    B.push_back({2, 1});

    std::vector<std::vector<int>> C = matrixMultiply(A, B);

    int rows = C.size();
    int cols = C[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (j > 0) {
                std::cout << ' ';
            }
            std::cout << C[i][j];
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
