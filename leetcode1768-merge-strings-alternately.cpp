/*
 * leetcode1768-merge-strings-alternately.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/09 14:23
 * @brief https://leetcode.com/problems/merge-strings-alternately
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string retStr;

        int len1 = word1.length();
        int len2 = word2.length();

        int min = std::min(len1, len2);
        for (int i = 0; i < min; ++i) {
            retStr += word1[i];
            retStr += word2[i];
        }

        retStr += word1.substr(min);
        retStr += word2.substr(min);

        return retStr;
    }
};

int main() {
    while (1) {
        std::string word1;
        std::string word2;

        std::cout << "Input word1: ";
        if (!std::getline(std::cin, word1)) {
            return 0;
        }

        std::cout << "Input word2: ";
        if (!std::getline(std::cin, word2)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.mergeAlternately(word1, word2);
        std::cout << ret << std::endl;
    }

    return 0;
}
