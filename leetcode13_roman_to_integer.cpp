/**
 * @file leetcode13_roman_to_integer.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/14 11:05:52
 * @brief https://leetcode.com/problems/roman-to-integer/
 *
 **/
#include <iostream>
#include <map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::map<std::string, int> str_map;
        str_map["I"] = 1;
        str_map["V"] = 5;
        str_map["X"] = 10;
        str_map["L"] = 50;
        str_map["C"] = 100;
        str_map["D"] = 500;
        str_map["M"] = 1000;
        str_map["IV"] = 4;
        str_map["IX"] = 9;
        str_map["XL"] = 40;
        str_map["XC"] = 90;
        str_map["CD"] = 400;
        str_map["CM"] = 900;

        int result = 0;
        int len = s.length();
        for (size_t i = 0; i <len;) {
            std::string sub = s.substr(i, 2);
            if (str_map.find(sub) != str_map.end()) {
                result += str_map[sub];
                i += 2;
            } else {
                sub = s.substr(i, 1);
                result += str_map[sub];
                i++;
            }
        }

        return result;
    }
};

int main() {
    while (1) {
        std::cout << "Input string (empty string to exit): ";
        std::string s;
        std::cin >> s;

        if (s.empty()) {
            return 0;
        }

        Solution solution;
        auto ret = solution.romanToInt(s);
        std::cout << ret << std::endl;
    }

    return 0;
}
