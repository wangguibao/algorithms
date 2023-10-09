/*
 * leetcode2390_removing_starts_from_a_string.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/09 16:40
 * @brief https://leetcode.com/problems/removing-stars-from-a-string
 */
#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    string removeStars(string s) {
        std::stack<char> st;
        int len = s.length();

        for (int i = 0; i < len; ++i) {
            if (s[i] == '*') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        std::stack<char> st2;
        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
        }

        std::string retStr;
        while (!st2.empty()) {
            retStr += st2.top();
            st2.pop();
        }

        return retStr;
    }
};

int main() {
    while (1) {
        std::string word;

        std::cout << "Input word: ";
        if (!std::getline(std::cin, word)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.removeStars(word);
        std::cout << ret << std::endl;
    }

    return 0;
}
