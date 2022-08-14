/**
 * @file leetcode12_integer_to_roman.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/14 10:41:11
 * @brief https://leetcode.com/problems/integer-to-roman/
 *
 **/
#include <iostream>
#include <map>

class Solution {
public:
    std::string intToRoman(int num) {
        std::map<int, std::string> num_map;
        num_map[1] = "I";
        num_map[5] = "V";
        num_map[10] = "X";
        num_map[50] = "L";
        num_map[100] = "C";
        num_map[500] = "D";
        num_map[1000] = "M";
        num_map[4] = "IV";
        num_map[9] = "IX";
        num_map[40] = "XL";
        num_map[90] = "XC";
        num_map[400] = "CD";
        num_map[900] = "CM";

        std::string result;
        int target;

        if (num >= 1000) {
            target = num / 1000;
            num = num % 1000;

            for (int i = 0; i < target; ++i) {
                result += num_map[1000];
            }
        }

        if (num >= 900) {
            result += num_map[900];
            num -= 900;
        }

        if (num >= 500) {
            result += num_map[500];
            num -= 500;
        }

        if (num >= 400) {
            result += num_map[400];
            num -= 400;
        }

        if (num >= 100) {
            target = num / 100;
            num = num % 100;

            for (int i = 0; i < target; ++i) {
                result += num_map[100];
            }
        }

        if (num >= 90) {
            result += num_map[90];
            num -= 90;
        }

        if (num >= 50) {
            result += num_map[50];
            num -= 50;
        }

        if (num >= 40) {
            result += num_map[40];
            num -= 40;
        }

        if (num >= 10) {
            target = num / 10;
            num = num % 10;

            for (int i = 0; i < target; ++i) {
                result += num_map[10];
            }
        }

        if (num >= 9) {
            result += num_map[9];
            num -= 9;
        }

        if (num >= 5) {
            result += num_map[5];
            num -= 5;
        }

        if (num >= 4) {
            result += num_map[4];
            num -= 4;
        }

        if (num >= 1) {
            for (int i = 0; i < num; ++i) {
                result += num_map[1];
            }
        }

        return result;
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
        auto ret = solution.intToRoman(x);
        std::cout << ret << std::endl;
    }

    return 0;
}
