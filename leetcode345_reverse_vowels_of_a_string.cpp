/*
 * leetcode345_reverse_vowels_of_a_string.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2024/04/03 14:36
 * @brief https://leetcode.com/problems/reverse-vowels-of-a-string
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        std::string result = s;
        std::set<char> dict {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        std::vector<char> chars;
        std::vector<int> pos;

        for (int i = 0; i < s.length(); ++i) {
            if (dict.find(s[i]) != dict.end()) {
                chars.push_back(s[i]);
                pos.push_back(i);
            }
        }

        int b = 0;
        int e = pos.size() - 1;

        while (b < e) {
            int temp = pos[b];
            pos[b] = pos[e];
            pos[e] = temp;
            ++b;
            --e;
        }

        for (int i = 0; i < pos.size(); ++i) {
            result[pos[i]] = chars[i];
        }


        return result;
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
        auto ret = solution.reverseVowels(word);
        std::cout << ret << std::endl;
    }

    return 0;
}
