/**
 * @file leetcode73_set_matrix_zeros.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/25 15:29
 * @brief https://leetcode.com/problems/set-matrix-zeroes
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::set<int> zeroRows;
        std::set<int> zeroCols;

        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        for (auto row: zeroRows) {
            for (int i = 0; i < cols; ++i) {
                matrix[row][i] = 0;
            }
        }

        for (auto col: zeroCols) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};

void printMatrix(std::vector<std::vector<int>>& matrix) {
    int row = matrix.size();
    int col = row;

    for (int i = 0; i < row; ++i) {
        auto &r = matrix[i];

        for (int j = 0; j < col; ++j) {
            if (j > 0) {
                std::cout << ' ';
            }
            std::cout << r[j];
        }

        std::cout << std::endl;
    }
}

int main() {
    while (1) {
        int n = 0;
        std::cout << "Input n (Ctrl-C to exit): " << std::endl;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::vector<std::vector<int>> matrix;
        for (int i = 0; i < n; ++i) {
            std::cout << n << " integers for row " << i << std::endl;
            std::vector<int> row;

            int ele;
            for (int i = 0; i < n; ++i) {
                std::cin >> ele;
                row.push_back(ele);
            }

            matrix.emplace_back(row);
        }

        printMatrix(matrix);
        std::cout << "===============" << std::endl;

        Solution solution;
        solution.setZeroes(matrix);
        printMatrix(matrix);
    }

    return 0;
}
