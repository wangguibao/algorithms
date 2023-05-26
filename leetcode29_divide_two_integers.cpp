/**
 * @file leetcode29_divide_two_integers.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/26 14:31
 * @brief https://leetcode.com/problems/divide-two-integers/
 *
 **/
#include <iostream>
#include <map>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int dividend_ll = dividend;
        long long int divisor_ll = divisor;

        if (divisor == 1) {
            return safe_check(dividend_ll);
        }

        if (divisor == -1) {
            return safe_check(0ll - dividend_ll);
        }

        bool diff_sign = false;

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            diff_sign = true;
        }

        if (dividend < 0) {
            dividend_ll = 0 - dividend_ll;
        }

        if (divisor < 0) {
            divisor_ll = 0 - divisor_ll;
        }

        if (dividend_ll < divisor_ll) {
            return 0;
        }

        int shift = 0;
        while ((divisor_ll << shift) <= dividend_ll) {
            ++shift;
        }

        --shift;
        long long newdivisor = (divisor_ll << shift);
        long long int quotient = 0;
        long long int remain = dividend_ll;
        while (remain > 0 && shift >= 0) {
            newdivisor = (divisor_ll << shift);
            remain -= newdivisor;
            if (remain >= 0) {
                quotient += (1 << (shift));
            } else {
                remain += newdivisor;
                --shift;
            }
        }

        if (diff_sign) {
            quotient = 0 - quotient;
        }

        return safe_check(quotient);
    }

private:
    int safe_check(long long int x) {
        if (x <= -0x80000000ll) {
            return -0x80000000;
        } else if (x > -0x80000000ll && x <= 0x7fffffffll) {
            return x;
        } else {
            return 0x7fffffff;
        }
    }
};

int main() {
    while (1) {
        std::cout << "Input dividend and divisor (control-C to exit): ";
        int dividend = 0;
        int divisor = 0;
        if (!(std::cin >> dividend >> divisor)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.divide(dividend, divisor);
        std::cout << ret << std::endl;
    }

    return 0;
}
