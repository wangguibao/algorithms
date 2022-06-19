/**
 * @file leetcode3_longest_substring_without_repeated_characters.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/06/19 17:17:36
 * @brief https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Key point: sliding window
 **/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
/*
 * Key points: recursion
 */
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int longest_so_far = 0;
        std::vector<int> occur(256, 0);

        int str_len = s.length();
        if (str_len == 0) {
            return 0;
        }

        int begin = 0;
        int end = begin + 1;

        ++occur[s[0]];
        longest_so_far = 1;

        while (end < str_len) {
            if (occur[s[end]] == 0) {
                ++occur[s[end]];
                size_t len = end - begin + 1;
                if (len > longest_so_far) {
                    longest_so_far= len;
                }
            }
            else {
                /*
                 * There is a character somewhere in current substring that
                 * equals with s[end]
                 *
                 * Find the character, move the `begin` cursor beyond it
                 */
                 for (int i = begin; i < end; ++i) {
                    if (s[i] == s[end]) {
                        begin = i + 1;
                        break;
                    } else {
                        --occur[s[i]];
                    }
                 }

            }
            ++end;
        }

        return longest_so_far;
    }
};

int main() {
    std::string s;

    while (1) {
        std::cout << "Input string (ctrl-z to exit): ";
        std::cin >> s;

        if (s.length() == 0) {
            return 0;
        }

        Solution solution;
        auto ret = solution.lengthOfLongestSubstring(s);

        std::cout << ret << std::endl;
    }

    return 0;
}
