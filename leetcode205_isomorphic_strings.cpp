/**
 * @file leetcode205_isomorphic_strings.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/03 14:09
 * @brief https://leetcode.com/problems/isomorphic-strings
 *
 **/
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::map<char, char> m;
        std::set<char> used;

        if (s.empty() || t.empty()) {
            return false;
        }

        size_t len = s.length();

        for (size_t i = 0; i < len; ++i) {
            char c = s[i];

            auto it = m.find(c);
            if (it == m.end()) {
                // Try to map to a char that is already used
                if (used.find(t[i]) != used.end()) {
                    return false;
                }

                m.insert({s[i], t[i]});
                used.insert(t[i]);
            } else {
                if (it->second != t[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    while (1) {
        std::cout << "string s (Ctrl-C to exit): ";

        std::string s;
        if (!std::getline(std::cin, s)) {
            return 0;
        }

        std::cout << "string t (Ctrl-C) to exit: ";
        std::string t;

        if (!std::getline(std::cin, t)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.isIsomorphic(s, t);

        std::cout << (ret ? "true" : "false") << std::endl;
    }

    return 0;
}
