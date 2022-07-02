/**
 * @file leetcode6_zigzag_conversion.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/02 16:31:02
 * @brief https://leetcode.com/problems/zigzag-conversion/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
/*
 * Key points: recursion
 */
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        std::vector<std::vector<char>> result_vec;
        result_vec.resize(numRows);

        size_t len = s.length();

        if (numRows <= 1) {
            return s;
        }

        int col = 0;
        size_t i = 0;
        for (; i < len; ++col) {
            for (size_t j = 0; j < numRows; ++j) {
                if ((col % (numRows - 1)) == 0) {
                    result_vec[j].push_back(s[i++]);
                    if (i >= len) {
                        break;
                    }
                } else {
                    if ((j + col) % (numRows - 1) == 0) {
                        result_vec[j].push_back(s[i++]);
                        if (i >= len) {
                            break;
                        }
                    } else {
                        result_vec[j].push_back(' ');
                    }
                }
            }
        }

        std::string result("");
        for (size_t i = 0; i < numRows; ++i) {
            for (size_t j = 0; j < result_vec[i].size(); ++j) {
#if 0
                std::cout << result_vec[i][j];
#endif
                if (result_vec[i][j] != ' ') {
                    result += result_vec[i][j];
                }
            }
#if 0
            std::cout << std::endl;
#endif
        }

        return result;
    }
};

int main() {
    std::string s;

    while (1) {
        std::cout << "Input string (ctrl-z to exit): ";
        std::getline(std::cin, s);

        if (s.length() == 0) {
            return 0;
        }

        int num_rows;
        std::cout << "Number of rows: ";
        std::cin >> num_rows;

        Solution solution;
        auto ret = solution.convert(s, num_rows);

        std::cout << ret << std::endl;
    }

    return 0;
}
