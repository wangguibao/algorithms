/**
 * @file leetcode5_longest_palindromic_substring_02_center_enumeration.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/06/26 15:43:22
 * @brief https://leetcode.com/problems/longest-palindromic-substring/
 *
 **/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
/*
 * Key points: Check each string position as palindrome center
 * Note that we must consider the position between two characters, since if a
 * palindrome has even length, the position is between two characters.
 */
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        size_t begin = 0;
        size_t end = 0;
        size_t len = 0;

        size_t total_len = s.length();

        for (size_t i = 0; i < total_len; ++i) {
            ssize_t cur_begin = i;
            ssize_t cur_end = i;

            // Check the center as s[i]
            while (cur_begin >= 0
                    && cur_end < total_len
                    && s[cur_begin] == s[cur_end]) {
                size_t cur_len = cur_end - cur_begin + 1;
                if (len < cur_len) {
                    begin = cur_begin;
                    end = cur_end;
                    len = cur_len;
                }

                --cur_begin;
                ++cur_end;
            }


            // Check the virtual center at position between s[i] and s[i+1]
            if (i == total_len-1) {
                break;
            }
            cur_begin = i;
            cur_end = i+1;
            while (cur_begin >= 0
                    && cur_end < total_len
                    && s[cur_begin] == s[cur_end]) {
                size_t cur_len = cur_end - cur_begin + 1;
                if (len < cur_len) {
                    begin = cur_begin;
                    end = cur_end;
                    len = cur_len;
                }

                --cur_begin;
                ++cur_end;
            }
        }
        return s.substr(begin, end - begin + 1);
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
