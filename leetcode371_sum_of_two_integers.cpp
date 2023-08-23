/**
 * @file leetcode371_sum_of_two_integers.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/08/23 15:31
 * @brief https://leetcode.com/problems/sum-of-two-integers/
 *
 **/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int ret = 0;
        int carry = 0;

        for (int i = 0; i < 32; ++i) {
            int bitA = a & 0x01;
            int bitB = b & 0x01;
            int lastCarry = carry;
            carry = 0;

            int add = bitA ^ bitB;
            if (add == 0 && bitA) {
                carry = 1;
            }

            add = add ^ lastCarry;
            if (add == 0 && lastCarry == 1) {
                carry = 1;
            }

            ret = ret | (add << i);
            a >>= 1;
            b >>= 1;
        }

        return ret;
    }

};

int main() {
    while (1) {
        std::cout << "Input two numbers (control-C to exit): ";
        int a = 0;
        int b = 0;
        if (!(std::cin >> a >> b)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.getSum(a, b);
        std::cout << ret << std::endl;
    }

    return 0;
}
