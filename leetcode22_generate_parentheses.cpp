/**
 * @file leetcode22_generate_parentheses.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/14 11:30:13
 * @brief https://leetcode.com/problems/generate-parentheses/
 *
 **/
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::string s;
        std::vector<std::string> result_vec;
        helper(n, 0, 0, s, result_vec);

        return result_vec;
    }

private:
    void helper(
            int n,
            int left,
            int right,
            std::string& s,
            std::vector<std::string>& result_vec) {
        if (left == n && right == n) {
            result_vec.push_back(s);
            return;
        }

        // Put a '('
        if (left < n) {
            s.push_back('(');
            helper(n, left+1, right, s, result_vec);
            s.pop_back();
        }

        if (right < left) {
            s.push_back(')');
            helper(n, left, right+1, s, result_vec);
            s.pop_back();
        }

        return;
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
        auto ret = solution.generateParenthesis(x);

        for (auto s: ret) {
            std::cout << s << std::endl;
        }
    }

    return 0;
}
