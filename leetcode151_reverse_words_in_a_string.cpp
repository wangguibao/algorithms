/**
 * leecode161_reverse_words_in_a_string.cpp
 * @author wangguibao (wang_guibao@163.com)
 * @date 2023/06/15 15:29
 * @brief https://leetcode.com/problems/reverse-words-in-a-string
 */
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string> sVec;
        split(s, sVec);

        int wordCnt = sVec.size();
        for (size_t i = 0; i < wordCnt; ++i) {
            std::cout << std::quoted(sVec[i]) << std::endl;
        }

        std::string ret;
        for (int i = wordCnt - 1; i >= 0; --i) {
            if (i < wordCnt - 1) {
                ret += " ";
            }
            ret += sVec[i];
        }
        return ret;
    }

private:
    void split(std::string s, std::vector<std::string>& sVec) {
        int b = 0;
        int e = s.length();

        int curBegin = b;
        bool bFound = false;
        while (b < e) {
            if (s[b] == ' ') {
                if (bFound) {
                    sVec.emplace_back(s.substr(curBegin, b - curBegin));
                    bFound = false;
                }
            } else {
                if (!bFound) {
                    bFound = true;
                    curBegin = b;
                }
            }
            ++b;
        }

        if (bFound) {
            sVec.emplace_back(s.substr(curBegin));
        }

        return;
    }
};

int main()
{
    while (1) {
        std::string s;
        std::cout << "Input string (Ctrl-C to exit):" << std::endl;
        if (!std::getline(std::cin, s)) {
            return 0;
        }

        std::cout << s << std::endl;

        Solution solution;
        auto ret = solution.reverseWords(s);
        std::cout << ret << std::endl;
    }
    return 0;
}
