/**
 * @file leetcode70_climbing_stairs.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/03 14:33
 * @brief https://leetcode.com/problems/climbing-stairs
 *
 **/
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        int ways[n];

        for (int i = 0; i < n; ++i) {
            ways[i] = 0;
        }

        ways[n - 1] = 1;
        ways[n - 2] = 2;
        for (int i = n - 3; i >= 0; --i) {
            ways[i] = ways[i+1] + ways[i+2];
        }
        return ways[0];
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
        auto ret = solution.climbStairs(x);
        std::cout << ret << std::endl;
    }

    return 0;
}
