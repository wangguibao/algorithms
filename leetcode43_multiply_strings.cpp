/**
 * leecode43_multiply_strings.cpp
 * @author wangguibao (wang_guibao@163.com)
 * @date 2023/07/28 18:02
 * @brief https://leetcode.com/problems/multiply-strings/
 */
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return std::string("0");
        }

        if (num1 == "1") {
            return num2;
        }

        if (num2 == "1") {
            return num1;
        }

        if (num1.length() < num2.length()) {
            std::swap(num1, num2);
        }
        int num1Len = num1.length();
        int num2Len = num2.length();

        std::vector<std::string> subProducts(num2Len);
        for (int i = num2Len - 1; i >= 0; --i) {
            std::string& subProduct = subProducts[i];
            int digit2 = num2[i] - '0';
            int carry = 0;
            int product = 0;

            for (int j = 0; j < num2Len - i - 1; ++j) {
                subProducts[i] += '0';
            }

            for (int j = num1Len - 1; j >= 0; --j) {
                int digit1 = num1[j] - '0';
                product = digit1 * digit2 + carry;
                carry = product / 10;
                product = product % 10;
                subProduct += product + '0';
            }

            while (carry > 0) {
                int remind = carry % 10;
                subProduct += remind + '0';
                carry = carry / 10;
            }
        }

        int maxLen = -1;
        for (int i = 0; i < num2Len; ++i) {
            int len = subProducts[i].length();
            if (len > maxLen) {
                maxLen = len;
            }
        }

        std::string result;
        int carry = 0;
        for (int i = 0; i < maxLen; ++i) {
            int sum = carry;
            for (size_t j = 0; j < subProducts.size(); ++j) {
                if (subProducts[j].length() <= i) {
                    continue;
                }
                sum += subProducts[j][i] - '0';
            }

            carry = sum / 10;
            sum = sum % 10;
            result += sum + '0';
        }

        while (carry > 0) {
            int remind = carry % 10;
            result += remind + '0';
            carry = carry / 10;
        }

        for (int b = 0, e = result.length() - 1; b < e; ++b, --e) {
            std::swap(result[b], result[e]);
        }
        return result;
    }
};

int main()
{
    while (1) {
        std::string s1;
        std::cout << "Input string 1 (Ctrl-C to exit):" << std::endl;
        if (!std::getline(std::cin, s1)) {
            return 0;
        }

        std::string s2;
        std::cout << "Input string 2 (Ctrl-C to exit):" << std::endl;
        if (!std::getline(std::cin, s2)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.multiply(s1, s2);
        std::cout << ret << std::endl;
    }
    return 0;
}
