/**
 * @file leetcode8_string_to_integer_atoi.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/16 11:40:02
 * @brief https://leetcode.com/problems/string-to-integer-atoi/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
/*
 * Key points: recursion
 */
class Solution {
public:
    int myAtoi(std::string s) {
        size_t len = s.length();

        if (len == 0) {
            return 0;
        }

        size_t begin = 0;
        while (s[begin] == ' ' && begin < len) {
            ++begin;
        }

        if (begin == len) {
            return 0;
        }

        int sign = 1;
        long long int result = 0;
        uint32_t max_limit = std::pow(2, 31);

        for (size_t i = begin; i < len; ++i) {
            if (s[i] == ' ') {
                break;
            } else if (s[i] == '+') {
                if (i != begin) {
                    break;
                }
            } else if (s[i] == '-') {
                if (i == begin) {
                    sign = 0;
                } else {
                    break;
                }
            } else if (s[i] == '.') {
                break;
            } else if ((s[i] >= 'A' && s[i] <= 'Z')
                    || (s[i] >= 'a' && s[i] <= 'z')) {
                break;
            } else if (s[i] >= '0' && s[i] <= '9') {
                result = result * 10 + s[i] - '0';
                if ((sign) && (result > max_limit - 1)) {
                    result = max_limit - 1;
                    break;
                } else if ((!sign) && (result > max_limit)) {
                    result = max_limit;
                    break;
                }
            }
        }

        return sign ? result : (0 - result);
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
        auto ret = solution.myAtoi(s);

        std::cout << ret << std::endl;
    }

    return 0;
}
