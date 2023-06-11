/**
 * @file leetcode200_number_of_islands.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2023/06/11 09:27
 * @brief https://leetcode.com/problems/number-of-islands
 **/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        size_t row = grid.size();
        size_t col = grid[0].size();

        std::vector<std::vector<bool>> traversed(row);
        for (size_t i = 0; i < row; ++i) {
            traversed[i].resize(col);

            for (size_t j = 0; j < col; ++j) {
                traversed[i][j] = false;
            }
        }

        int nIslands = 0;
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }

                if (traversed[i][j]) {
                    continue;
                }

                dfs(grid, traversed, i, j);
                ++nIslands;
            }
        }

        return nIslands;
    }

private:
    void dfs(
            std::vector<std::vector<char>>& grid,
            std::vector<std::vector<bool>>& traversed,
            size_t i,
            size_t j) {
        if (traversed[i][j]) {
            return;
        }

        traversed[i][j] = true;
        if (j > 0 && grid[i][j-1] == '1') {
            dfs(grid, traversed, i, j - 1);
        }

        if (j + 1 < grid[0].size() && grid[i][j+1] == '1') {
            dfs(grid, traversed, i, j + 1);
        }

        if (i > 0 && grid[i - 1][j] == '1') {
            dfs(grid, traversed, i - 1, j);
        }

        if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
            dfs(grid, traversed, i + 1, j);
        }
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

        std::vector<std::vector<char>> matrix;

        for (int i = 0; i < m; ++i) {
            std::vector<char> row;

            std::cout << n << " chars for row " << i << std::endl;

            for (int j = 0; j < n; ++j) {
                char x;
                std::cin >> x;
                row.push_back(x);
            }

            matrix.push_back(row);
        }

        Solution solution;
        auto ret = solution.numIslands(matrix);

        std::cout << ret << std::endl;
    }

    return 0;
}
