/**
 * @file leetcode392_is_subsequence.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/31 22:39
 * @brief https://leetcode.com/problems/is-subsequence
 *
 **/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t slen = s.length();
        size_t tlen = t.length();

        if (slen == 0) {
            return true;
        }

        if (slen > 0 && tlen <= 0) {
            return false;
        }

        if (slen > tlen) {
            return false;
        }

        size_t matched = 0;
        size_t sp = 0;
        size_t tp = 0;

        while (sp < slen && tp < tlen) {
            if (s[sp] == t[tp]) {
                ++matched;
                ++sp;
                ++tp;
                if (matched >= slen) {
                    return true;
                }
            } else {
                ++tp;
            }
        }

        return false;
    }
};

int main() {
    std::string s;
    std::string t;

    while (1) {
        std::cout << "Input string s (Ctrl-C to exit): ";
        std::getline(std::cin, s);
        if (!std::cin) {
            return 0;
        }

        std::cout << "Input string t (Ctrl-C to exit):";
        std::getline(std::cin, t);
        if (!std::cin) {
            return 0;
        }

        Solution solution;
        auto ret = solution.isSubsequence(s, t);

        std::cout << (ret ? "true" : "false") << std::endl;
    }

    return 0;
}
