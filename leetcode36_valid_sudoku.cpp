/**
 * @file leetcode36_valid_sudoku.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/01 23:10
 * @brief https://leetcode.com/problems/valid-sudoku
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        size_t len = board.size();

        // Each row
        for (size_t i = 0; i < len; ++i) {
            std::vector<bool> s(10, false);
            for (size_t j = 0; j < len; ++j) {
                char x = board[i][j];
                if (x >= '1' && x <= '9') {
                    if (s[x - '1']) {
                        return false;
                    }
                    s[x - '1'] = true;
                }
            }
        }

        // Each column
        for (size_t i = 0; i < len; ++i) {
            std::vector<bool> s(10, false);

            for (size_t j = 0; j < len; ++j) {
                char x = board[j][i];
                if (x >= '1' && x <= '9') {
                    if (s[x - '1']) {
                        return false;
                    }
                    s[x - '1'] = true;
                }
            }
        }

        // Each 3 x 3 subbox
        std::vector<std::vector<bool>> subboxes;
        subboxes.resize(9);
        for (size_t i = 0; i < 9; ++i) {
            subboxes[i].resize(10);
        }

        for (size_t i = 0; i < len; ++i) {
            for (size_t j = 0; j < len; ++j) {
                int row = i / 3;
                int col = j / 3;
                int index = row * 3 + col;
                int x = board[i][j];

                if (x >= '1' && x <= '9') {
                    if (subboxes[index][x - '1']) {
                        return false;
                    }

                    subboxes[index][x - '1'] = true;
                }
            }
        }
        return true;
    }
};

int main() {

    while (1) {
        int n = 0;
        std::cout << "Matrix dimension (ctrl-c to exit): ";
        if (!(std::cin >> n)) {
            return 0;
        }

        if (n <= 0) {
            continue;
        }

        std::vector<std::vector<char>> board;

        for (int i = 0; i < n; ++i) {
            std::cout << n << " chars for row " << i << std::endl;
            std::vector<char> row;

            char ele;
            for (int j = 0; j < n; ++j) {
                std::cin >> ele;
                row.push_back(ele);
            }

            board.push_back(row);
        }

        Solution solution;
        auto ret = solution.isValidSudoku(board);

        std::cout << (ret ? "true" : "false") << std::endl;
    }

    return 0;
}
