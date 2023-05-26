/**
 * @file leetcode76_minimum_window_substring.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/26 18:13
 * @brief https://leetcode.com/problems/minimum-window-substring/
 *
 **/
#include <iostream>
#include <map>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        std::string ret_str;

        int candidate_begin = 0;
        size_t candidate_len = INT_MAX;

        size_t slen = s.length();
        size_t tlen = t.length();

        std::map<char, int> m_t;
        for (size_t i = 0; i < tlen; ++i) {
            auto iter = m_t.find(t[i]);
            if (iter == m_t.end()) {
                m_t.insert({t[i], 1});
            } else {
                ++iter->second;
            }
        }

        size_t left = 0;
        size_t p = left;
        size_t right = slen - 1;

        int finished_chars = 0;
        int uniq_chars = m_t.size();

        while (p <= right || finished_chars >= uniq_chars) {
            if (finished_chars >= uniq_chars) {
                if (candidate_len > p - left) {
                    candidate_begin = left;
                    candidate_len = p - left;
                }

                // Shrink left
                auto c = s[left];
                ++left;
                auto iter = m_t.find(c);

                if (iter != m_t.end()) {
                    ++m_t[c];
                    if (m_t[c] == 1) {
                        --finished_chars;
                    }
                }
            }
            else {
                // expand right
                auto c = s[p];
                ++p;
                auto iter = m_t.find(c);

                if (iter != m_t.end()) {
                    --m_t[c];
                    if (m_t[c] == 0) {
                        ++finished_chars;
                    }
                }
            }
        }

        return candidate_len < INT_MAX?
            s.substr(candidate_begin, candidate_len)
            : std::string();
    }
};

int main() {
    while (1) {
        std::cout << "Input strings s and t(control-C to exit): ";
        std::string s;
        std::string t;
        std::getline(cin, s);
        std::getline(cin, t);

        Solution solution;
        auto ret = solution.minWindow(s, t);
        std::cout << ret << std::endl;
    }

    return 0;
}
