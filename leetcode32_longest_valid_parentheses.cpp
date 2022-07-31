/**
 * @file leetcode32_longest_valid_parentheses.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/31 17:44:31
 * @brief https://leetcode.com/problems/longest-valid-parentheses/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    int longestValidParentheses(std::string s) {
        /*
         * Key points: Dynamic Programming
         *
         * First come up in mind: for each i and j, check if s[i:j] contains
         * valid parentheses. But there are many duplicate sub problems.
         *
         * 1) Starting from each pair of closed '()' patterns
         * 2) If we have known s[i:j] contains valid parentheses, then when we
         * go to s[i - 1], there may be several possible cases:
         *   (1) s[i - 1] == '(', s[i:j] has valid parentheses, s[j+1] = ')'
         *   (2) s[j-1 : j] has valid parentheses, s[j + 1: k] has valid
         *       parenetheses
         *   in either case the length starting from s[i - 1] should be updated
         *
         * Corner case:
         * in case (1), if we find s[i - 1: j + 1] has valid parentheses, we want
         * to further check if there are consequtive substrings that also has
         * valid prentheses
         *
         * example: "((()))())"
         */
        ssize_t len = s.length();
        std::vector<int> result_vec(len, 0);

        for (ssize_t i = len - 2; i >= 0; --i) {
            if (s[i] == '(' && s[i+1] == ')') {
                result_vec[i] = 2;
            }
        }

        for (ssize_t i = len - 2; i >= 0; --i) {
            int len1 = 0;
            if (s[i] == '('
                    && result_vec[i+1] > 0
                    && (i + result_vec[i+1] + 1) < len
                    && s[i + result_vec[i+1] + 1] == ')') {
                len1 = result_vec[i+1] + 2;
            }

            if ((i + len1 < len) && result_vec[i + len1] > 0) {
                len1 += result_vec[i + len1];
            }

            int len2 = 0;
            if (result_vec[i] > 0
                    && (i + result_vec[i]) < len
                    && result_vec[i + result_vec[i]] > 0) {
                len2 = result_vec[i] + result_vec[i+result_vec[i]];
            }

            int max_len = std::max(len1, len2);
            if (result_vec[i] < max_len) {
                result_vec[i] = max_len;
            }
        }

        int max_len = 0;
        for (ssize_t i = 0; i < len; ++i) {
            if (max_len < result_vec[i]) {
                max_len = result_vec[i];
            }
        }

        return max_len;
    }
};

int main() {
    while (1) {
        std::cout << "Input string (only '(' and ')'), empty string to exit: ";
        std::string s;
        std::getline(std::cin, s);

        if (s.empty()) {
            return 0;
        }

        Solution solution;
        int ret = solution.longestValidParentheses(s);

        std::cout << ret << std::endl;
    }

    return 0;
}
