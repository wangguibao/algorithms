/**
 * @file leetcode289_game_of_life.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/07/01 17:45
 * @brief https://leetcode.com/problems/game-of-life
 *
 * The inplace solution is from Stefan Pochmann (https://leetcode.com/StefanPochmann/)
 * which can be found at
 * https://leetcode.com/problems/game-of-life/solutions/73230/c-o-1-space-o-mn-time/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighborCnt = 0;
                for (int k = std::max(i - 1, 0); k < std::min(i + 2, m); ++k) {
                    for (int l = std::max(j - 1, 0); l < std::min(j + 2, n); ++l) {
                        neighborCnt += board[k][l] & 1;
                    }
                }

                if (neighborCnt == 3 || neighborCnt - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }
        }


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};

void printMatrix(std::vector<std::vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

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
        int m = 0;
        int n = 0;
        std::cout << "Input m and n (Ctrl-C to exit): " << std::endl;
        if (!(std::cin >> m >> n)) {
            return 0;
        }

        std::vector<std::vector<int>> matrix;
        for (int i = 0; i < m; ++i) {
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
        solution.gameOfLife(matrix);
        printMatrix(matrix);
    }

    return 0;
}
