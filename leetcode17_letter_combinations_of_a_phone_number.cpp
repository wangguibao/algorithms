/**
 * @file leetcode17_letter_combinations_of_a_phone_number.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/04 10:47:57
 * @brief https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
#include <map>
class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }

        _digit_to_letter_map['2'] = {'a', 'b', 'c'};
        _digit_to_letter_map['3'] = {'d', 'e', 'f'};
        _digit_to_letter_map['4'] = {'g', 'h', 'i'};
        _digit_to_letter_map['5'] = {'j', 'k', 'l'};
        _digit_to_letter_map['6'] = {'m', 'n', 'o'};
        _digit_to_letter_map['7'] = {'p', 'q', 'r', 's'};
        _digit_to_letter_map['8'] = {'t', 'u', 'v'};
        _digit_to_letter_map['9'] = {'w', 'x', 'y', 'z'};

        std::vector<std::vector<char>> result_vec;
        std::vector<char> cur_res;
        _letter_combinations(digits, 0, cur_res, result_vec);

        for (auto com: result_vec) {
            std::string s;
            for (auto ch: com) {
                s += ch;
            }

            result.push_back(s);
        }
        return result;
    }

private:
    void _letter_combinations(
            std::string digits,
            int pos,
            std::vector<char>& cur_res,
            std::vector<std::vector<char>>& result_vec) {
        if (pos >= digits.size()) {
            result_vec.push_back(cur_res);
            return;
        }

        auto letters = _digit_to_letter_map[digits.at(pos)];
        for (auto letter: letters) {
            cur_res.push_back(letter);
            _letter_combinations(digits, pos + 1, cur_res, result_vec);
            cur_res.pop_back();
        }

        return;
    }

private:
    std::map<char, std::vector<char>> _digit_to_letter_map;
};

int main() {
    while (1) {
        std::cout << "Input string (only '2' to '9'), empty string to exit: ";
        std::string s;
        std::getline(std::cin, s);

        if (s.empty()) {
            return 0;
        }

        Solution solution;
        auto ret = solution.letterCombinations(s);

        for (auto comb: ret) {
            std::cout << comb << std::endl;
        }
    }

    return 0;
}
