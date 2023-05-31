/**
 * @file leetcode58_length_of_last_word.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/27 11:08
 * @brief https://leetcode.com/problems/length-of-last-word/
 *
 **/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        size_t len = s.length();

        int b = 0;
        int e = len - 1;
        while (b <= e) {
            if (!isalnum(s[b])) {
                ++b;
                continue;
            }

            if (!isalnum(s[e])) {
                --e;
                continue;
            }

            if (tolower(s[b]) != tolower(s[e])) {
                return false;
            }

            ++b;
            --e;
        }

        return true;
    }
};

int main() {
    std::string s;

    while (1) {
        std::cout << "Input string (empty string to exit): ";
        std::getline(std::cin, s);

        if (s.length() == 0) {
            return 0;
        }

        Solution solution;
        auto ret = solution.isPalindrome(s);

        std::cout << (ret ? "true" : "false") << std::endl;
    }

    return 0;
}
