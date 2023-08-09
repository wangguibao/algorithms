/**
 * @file leetcode79_word_search.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2023/08/09 20:01
 * @brief https://leetcode.com/problems/word-search/
 **/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        std::vector<std::vector<bool>> used;
        for (int i = 0; i < rows; ++i) {
            std::vector<bool> row(cols, false);
            used.push_back(row);
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    bool found = dfs(board, rows, cols, used, i, j, word, word.length(), 0);
                    if (found) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool dfs(
            std::vector<std::vector<char>>& board,
            int rows,
            int cols,
            std::vector<std::vector<bool>>& used,
            int curRow,
            int curCol,
            std::string word,
            int wordLen,
            int curCharPos) {
        if (used[curRow][curCol]) {
            return false;
        }

        if (board[curRow][curCol] != word[curCharPos]) {
            return false;
        }

        used[curRow][curCol] = true;
        if (curCharPos+1 == wordLen) {
            return true;
        }

        if (curRow > 0 && !used[curRow - 1][curCol]) {
            if (dfs(board, rows, cols, used, curRow - 1, curCol, word, wordLen, curCharPos + 1)) {
                return true;
            }
        }

        if (curCol + 1 < cols && !used[curRow][curCol+1]) {
            if (dfs(board, rows, cols, used, curRow, curCol+1, word, wordLen, curCharPos + 1)) {
                return true;
            }
        }

        if (curRow + 1 < rows && !used[curRow+1][curCol]) {
            if (dfs(board, rows, cols, used, curRow+1, curCol, word, wordLen, curCharPos+1)) {
                return true;
            }
        }

        if (curCol > 0 && !used[curRow][curCol - 1]) {
            if (dfs(board, rows, cols, used, curRow, curCol-1, word, wordLen, curCharPos+1)) {
                return true;
            }
        }

        used[curRow][curCol] = false;
        return false;
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

        cin.get();

        std::string word;
        std::cout << "Word to search:";
        std::getline(std::cin, word);

        Solution solution;
        auto ret = solution.exist(matrix, word);

        std::cout << (ret ? "TRUE" : "FALSE") << std::endl;
    }

    return 0;
}
