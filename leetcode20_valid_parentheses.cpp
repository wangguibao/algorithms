/**
 * @file leetcode20_valid_parentheses.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/03 14:50:42
 * @brief https://leetcode.com/problems/valid-parentheses/
 *
 **/
#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.empty()) {
            return true;
        }

        std::stack<char> st;
        size_t len = s.length();
        for (size_t i = 0; i < len; ++i) {
            switch (s[i]) {
            case '(':
            case '{':
            case '[':
                st.push(s[i]);
                break;
            case ')':
                if (st.empty() || st.top() != '(') {
                    return false;
                }

                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{') {
                    return false;
                }

                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[') {
                    return false;
                }

                st.pop();
                break;
            default:
                return false;
            }
        }

        if (!st.empty()) {
            return false;
        }

        return true;
    }
};

int main() {
    std::string s;

    while (1) {
        std::cout << "Input string (empty string to exit): ";
        std::getline(std::cin, s, '\n');

        if (s.empty()) {
            return 0;
        }

        Solution solution;
        auto ret = solution.isValid(s);

        std::cout << ret << std::endl;
    }

    return 0;
}
