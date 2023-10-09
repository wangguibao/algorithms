/*
 * leetcode150-spiral-matrix.cpp
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/07 19:20
 * @brief https://leetcode.com/problems/spiral-matrix
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int rowStart = 0;
        int rowEnd = rows - 1;
        int colStart = 0;
        int colEnd = cols - 1;

        std::vector<int> resVec;
        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int col = colStart; col <= colEnd; ++col) {
                resVec.push_back(matrix[rowStart][col]);
            }
            ++rowStart;
            if (rowStart > rowEnd) {
                break;
            }

            for (int row = rowStart; row <= rowEnd; ++row) {
                resVec.push_back(matrix[row][colEnd]);
            }
            --colEnd;
            if (colEnd < colStart) {
                break;
            }

            for (int col = colEnd; col >= colStart; --col) {
                resVec.push_back(matrix[rowEnd][col]);
            }
            --rowEnd;
            if (rowEnd < rowStart) {
                break;
            }

            for (int row = rowEnd; row >= rowStart; --row) {
                resVec.push_back(matrix[row][colStart]);
            }
            ++colStart;
            if (colStart > colEnd) {
                break;
            }
        }

        return resVec;
    }
};

int main() {
    while (1) {
        std::cout << "Number of rows:" << std::endl;
        int m;
        if (!(std::cin >> m)) {
            return -1;
        }

        std::cout << "Number of colums:" << std::endl;
        int n;
        if (!(std::cin >> n)) {
            return -1;
        }

        std::vector<std::vector<int>> matrix;

        for (int i = 0; i < m; ++i) {
            std::cout << "Input " << n << " elements for row " << i << std::endl;

            std::vector<int> row;
            for (int j = 0; j < n; ++j) {
                int x;
                std::cin >> x;
                row.push_back(x);
            }

            matrix.push_back(row);
        }

        Solution solution;

        auto ret = solution.spiralOrder(matrix);
        for (int i = 0; i < ret.size(); ++i) {
            if (i > 0) {
                std::cout << " ";
            }
            std::cout << ret[i];
        }
        std::cout << endl;
    }

    return 0;
}
