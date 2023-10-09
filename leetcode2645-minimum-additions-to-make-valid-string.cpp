/*
 * leetcode2645-minimum-additions-to-make-valid-string.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/09 14:45
 * @brief https://leetcode.com/problems/minimum-additions-to-make-valid-string/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        int len = word.length();

        int n = 0;
        int i = 0;
        int curLen = 0;

        while (i < len) {
            char c = word[i];

            switch (c) {
            case 'a':
                if (curLen == 0) {
                    ++curLen;
                } else if (curLen == 1) {
                    n += 2;
                } else if (curLen == 2) {
                    n += 1;
                    curLen = 1;
                }

                break;
            case 'b':
                if (curLen == 0) {
                    n += 1;
                    curLen = 2;
                } else if (curLen == 1) {
                    ++curLen;
                } else if (curLen == 2) {
                    n += 2;
                }
                break;

            case 'c':
                if (curLen == 0) {
                    n += 2;
                } else if (curLen == 1) {
                    n += 1;
                    curLen = 0;
                } else if (curLen == 2) {
                    curLen = 0;
                }
                break;

            default:
                break;
            }

            ++i;
        }

        if (curLen > 0) {
            n += (3 - curLen);
        }

        return n;
    }
};

int main() {
    while (1) {
        std::string word;

        std::cout << "Input word: ";
        if (!std::getline(std::cin, word)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.addMinimum(word);
        std::cout << ret << std::endl;
    }

    return 0;
}
