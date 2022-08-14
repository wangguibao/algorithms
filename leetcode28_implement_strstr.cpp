/**
 * @file leetcode28_implement_strstr.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/14 12:03:05
 * @brief https://leetcode.com/problems/implement-strstr/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }

        int s_len = haystack.length();
        int d_len = needle.length();
        if (s_len < d_len) {
            return -1;
        }

        for (int i = 0; i < s_len; ++i) {
            bool found = true;
            for (int j = 0; j < d_len; ++j) {
                if (haystack[i+j] != needle[j]) {
                    found = false;
                    break;
                }
            }

            if (found) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    std::string s;

    while (1) {
        std::string haystack;
        std::cout << "Input haystack (empty string to exit): ";
        std::getline(std::cin, haystack);

        if (haystack.length() == 0) {
            return 0;
        }

        std::string needle;
        std::cout << "Input needle (empty string to exit): ";
        std::getline(std::cin, needle);

        if (needle.length() == 0) {
            return 0;
        }

        Solution solution;
        auto ret = solution.strStr(haystack, needle);

        std::cout << ret << std::endl;
    }

    return 0;
}
