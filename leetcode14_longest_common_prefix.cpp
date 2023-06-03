/**
 * @file leetcode14_longest_common_prefix.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/03 11:43
 * @brief https://leetcode.com/problems/longest-common-prefix
 *
 **/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string ret;
        size_t size = strs.size();

        if (size == 0) {
            return ret;
        }

        if (size == 1) {
            return strs[0];
        }

        size_t minStrLen = INT_MAX;
        for (size_t i = 0; i < size; ++i) {
            size_t len = strs[i].length();
            if (minStrLen> len) {
                minStrLen = len;
            }
        }

        for (size_t i = 0; i < minStrLen; ++i) {
            char ch = strs[0][i];
            bool same = true;
            for (size_t j = 1; j < size; ++j) {
                if (strs[j][i] != ch) {
                    same =false;
                    break;
                }
            }

            if (same) {
                ret += ch;
            } else {
                break;
            }
        }

        return ret;
    }
};

int main() {
    while (1) {
        std::cout << "Number of strings (Ctrl-C to exit): ";
        int n;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::string s;
        std::getline(std::cin, s);

        std::vector<std::string> strs;
        std::cout << n << " strings: " << std::endl;
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, s);
            strs.emplace_back(s);
        }

        Solution solution;
        auto ret = solution.longestCommonPrefix(strs);

        std::cout << ret << std::endl;
    }

    return 0;
}
