/**
 * @file leetcode48_rotate_image.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/25 14:24
 * @brief https://leetcode.com/problems/rotate-image
 *
 * Solution by shichaotan@leetcode (https://leetcode.com/shichaotan/)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
         * Solution:
         * https://leetcode.com/problems/rotate-image/solutions/18872/a-common-method-to-rotate-the-image/
         * flip vertically, then flip around the upleft-to-downright diagonal line
         *
         * 1 2 3      7 8 9     7 4 1
         * 4 5 6  =>  4 5 6  => 8 5 2
         * 7 8 9      1 2 3     9 6 3
         */

        // 1. flip vertically
        int rows = matrix.size();
        int b = 0;
        int e = rows - 1;
        while (b < e) {
            matrix[b].swap(matrix[e]);
            ++b;
            --e;
        }

        // 2. flip around the upleft-to-downright diagonal line
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
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
        solution.rotate(matrix);
        printMatrix(matrix);
    }

    return 0;
}
