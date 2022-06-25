/**
 * @file leetcode3_longest_palindromic_substring_01_dp.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/06/25 13:55:01
 * @brief https://leetcode.com/problems/longest-palindromic-substring/
 *
 **/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
/*
 * Key points: dynamic programming
 * define dp[i][j] = 1 if substring[i, j] is palindrome
 *                   0 if substring[i, j] is not palindrome
 * for all [i, j] that dp[i][j] = 1, return max(j - i)
 *
 * The formula
 * dp[i][j] = (s[i] == s[j] && dp[i+1][j-1])
 * special case:
 * if j - i == 1 || j - i == 2, then: if (s[i] == s[j]) {dp[i][j] = 1;}
 */
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::vector<std::vector<bool>> dp;
        size_t total_len = s.length();

        dp.resize(total_len);
        for (size_t i = 0; i < total_len; ++i) {
            dp[i].resize(total_len);
        }

        for (size_t i = 0; i < total_len; ++i) {
            dp[i][i] = true;
        }

        size_t max_len = 1;
        int x = 0;
        int y = 0;

        for (int i = total_len - 1; i >= 0; --i) {
            for (size_t j = i + 1; j < total_len; ++j) {
                if (j - i == 1 || j - i == 2) {
                    if (s[j] == s[i]) {
                        dp[i][j] = true;
                        if (max_len < j - i + 1) {
                            max_len = j - i + 1;
                            x = i;
                            y = j;
                        }
                    }
                }
                else if (s[j] == s[i]  && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (max_len < j - i + 1) {
                        max_len = j - i + 1;
                        x = i;
                        y = j;
                    }
                }
            }
        }

        return s.substr(x, y - x + 1);
    }
};

int main() {
    std::string s;

    while (1) {
        std::cout << "Input string (empty string to exit): ";
        std::getline(std::cin, s, '\n');

        if (s.empty()) {
            return 0;
        }

        Solution solution;
        auto ret = solution.longestPalindrome(s);

        std::cout << ret << std::endl;
    }

    return 0;
}
