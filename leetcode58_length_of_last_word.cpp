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
    int lengthOfLastWord(string s) {
        std::string word;

        std::istringstream iss(s);

        while (iss >> word) {
        }

        return word.length();
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
        auto ret = solution.lengthOfLastWord(s);

        std::cout << ret << std::endl;
    }

    return 0;
}
