/**
 * @file leetcode9_palindrome_number.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/27 11:00
 * @brief https://leetcode.com/problems/palindrome-number
 *
 **/
#include <iostream>
#include <sstream>

#include <queue>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        std::ostringstream oss;
        oss << x;

        std::string str = oss.str();

        size_t size = str.length();
        int b = 0;
        int e = size - 1;

        while (b < e) {
            if (str[b] != str[e]) {
                return false;
            }
            ++b;
            --e;
        }
        return true;
    }
};

int main() {
    while (1) {
        std::cout << "Input integer (control-C to exit): ";
        int x = 0;
        if (!(std::cin >> x)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.isPalindrome(x);
        std::cout << (ret ? "true" : "false") << std::endl;
    }

    return 0;
}
