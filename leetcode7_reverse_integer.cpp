/**
 * @file leetcode7_reverse_integer.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/05 10:17:10
 * @brief https://leetcode.com/problems/reverse-integer/
 *
 **/
#include <iostream>
#include <queue>
#include <cmath>

/**
 * My initial idea (not working) idea:
 * 1. Extract the sign
 * 2. Reverse remaining digits part
 * 3. append a sign
 */
class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x) {
            int pop = x % 10;
            x = x / 10;

            if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && pop > 7)) {
                return 0;
            }

            if (rev < (INT_MIN / 10) || (rev == (INT_MIN / 10) && pop < -8)) {
                return 0;
            }

            rev = rev * 10 + pop;
        }
        return rev;
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
        auto ret = solution.reverse(x);
        std::cout << ret << std::endl;
    }

    return 0;
}
