/**
 * @file leetcode172_factorial_trailing_zeros.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/14 19:18
 * @brief https://leetcode.com/problems/factorial-trailing-zeroes/
 *
 **/
#include <iostream>
#include <queue>
#include <cmath>

class Solution {
public:
    int trailingZeroes(int x) {
        int n2 = 0;
        int n5 = 0;
        int n10 = 0;
        for (int i = 1; i <= x; ++i) {
            int j = i;
            while (j % 10 == 0) {
                ++n10;
                j /= 10;
            }

            while (j % 5 == 0) {
                ++n5;
                j /= 5;
            }

            while (j % 2 == 0) {
                ++n2;
                j /= 2;
            }
        }

        int ret = n10;
        int n = std::min(n2, n5);
        ret += n;  

        return ret;
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
        auto ret = solution.trailingZeroes(x);
        std::cout << ret << std::endl;
    }

    return 0;
}
