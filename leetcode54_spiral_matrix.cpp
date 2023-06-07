/**
 * @file leetcode54_spiral_matrix.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2023/06/07 21:46
 * @brief https://leetcode.com/problems/spiral-matrix
 **/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> retVec;

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (true) {
            for (int i = left; i <= right; ++i) {
                retVec.emplace_back(matrix[top][i]);
            }
            ++top;
            if (left > right || top > bottom) {
                break;
            }

            for (int i = top; i <= bottom; ++i) {
                retVec.emplace_back(matrix[i][right]);
            }
            --right;
            if (left > right || top > bottom) {
                break;
            }

            for (int i = right; i >= left; --i) {
                retVec.emplace_back(matrix[bottom][i]);
            }
            --bottom;
            if (left > right || top > bottom) {
                break;
            }

            for (int i = bottom; i >= top; --i) {
                retVec.emplace_back(matrix[i][left]);
            }
            ++left;

            if (left > right || top > bottom) {
                break;
            }

        }

        return retVec;
    }
};

int main() {
    while (1) {
        std::cout << "row and col of matrix (Ctrl-C exits): " << std::endl;
        int m;
        int n;
        if (!(std::cin >> m >> n)) {
            break;
        }

        std::vector<std::vector<int>> matrix;

        for (int i = 0; i < m; ++i) {
            std::vector<int> row;

            std::cout << n << " integers for row " << i << std::endl;

            for (int j = 0; j < n; ++j) {
                int x;
                std::cin >> x;
                row.push_back(x);
            }

            matrix.push_back(row);
        }

        Solution solution;
        auto ret = solution.spiralOrder(matrix);

        size_t size = ret.size();
        for (size_t i = 0; i < size; ++i) {
            std::cout << ret[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
