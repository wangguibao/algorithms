/*
 * leetcode1071-greatst-common-divisor-of-strings.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/09 15:59
 * @brief https://leetcode.com/problems/greatest-common-divisor-of-strings
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        std::string gcd;
        while (!str1.empty() && ! str2.empty()) {
            if (str1.length() == str2.length()) {
                if (str1 == str2) {
                    gcd = str1;
                }
                break;
            } else if (str1.length() > str2.length()) {
                if (str1.substr(0, str2.length()) != str2) {
                    break;
                }
                str1 = str1.substr(str2.length());
            } else {
                if (str2.substr(0, str1.length()) != str1) {
                    break;
                }
                str2 = str2.substr(str1.length());
            }
        }

        return gcd;
    }
};

int main() {
    while (1) {
        std::string str1;
        std::string str2;

        std::cout << "Input str1: ";
        if (!std::getline(std::cin, str1)) {
            return 0;
        }

        std::cout << "Input str2: ";
        if (!std::getline(std::cin, str2)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.gcdOfStrings(str1, str2);
        std::cout << ret << std::endl;
    }

    return 0;
}
