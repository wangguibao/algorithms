/**
 * @file leetcode290_word_pattern.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/07 22:15
 * @brief https://leetcode.com/problems/word-pattern
 *
 **/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::map<char, std::string> m;
        std::set<std::string> used;

        std::vector<std::string> words;
        stringSplit(s, words);

        size_t plen = pattern.length();
        if (plen != words.size()) {
            return false;
        }

        for (size_t i = 0; i < plen; ++i) {
            char c = pattern[i];
            auto iter = m.find(c);
            if (iter == m.end()) {
                if (used.find(words[i]) != used.end()) {
                    return false;
                }
                m.insert({c, words[i]});
                used.insert(words[i]);
            } else {
                auto prev_word = iter->second;
                if (prev_word != words[i]) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    void stringSplit(std::string s, std::vector<std::string>& words) {
        std::stringstream iss(s);

        std::string word;
        while (iss >> word) {
            words.emplace_back(word);
        }
    }
};

int main() {
    while (1) {
        std::cout << "pattern string (Ctrl-C to exit): ";

        std::string pattern;
        if (!std::getline(std::cin, pattern)) {
            return 0;
        }

        std::cout << "s string (Ctrl-C) to exit: ";
        std::string s;

        if (!std::getline(std::cin, s)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.wordPattern(pattern, s);

        std::cout << (ret ? "true" : "false") << std::endl;
    }

    return 0;
}
