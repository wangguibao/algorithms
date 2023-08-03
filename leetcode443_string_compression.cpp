/**
 * @file leetcode443_string_compression.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/08/03 17:00
 * @brief https://leetcode.com/problems/string-compression/
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int p = 0;
        int size = chars.size();

        int s = 0;
        int e = 0;
        int repeat = 0;
        while (e < size) {
            while ((e < size) && (chars[s] == chars[e])) {
                ++repeat;
                ++e;
            }
            chars[p++] = chars[s];
            if (repeat > 1) {
                bool start = false;
                int div = 1000;
                while (div) {
                    int remain = repeat / div;
                    repeat = repeat % div;
                    div = div / 10;
                    if (remain && (start == false)) {
                        start = true;
                    }

                    if (!start) {
                        continue;
                    }
                    chars[p++] = remain + '0';

                }
            }
            s = e;
            repeat = 0;
        }

        chars.resize(p);
        return p;
    }
};

int main() {
    int n;
    std::vector<char> chars;

    while (1) {
        n = 0;
        std::cout << "Number of characters (Ctrl-C to exit): " << std::endl;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " characters: " << std::endl;
        chars.clear();

        char ele;
        for (int i = 0; i < n; ++i) {
            std::cin >> ele;
            chars.push_back(ele);
        }

        Solution solution;
        auto ret = solution.compress(chars);
        std::cout << ret << std::endl;

        for (auto x: chars) {
            std::cout << x;
        }
        std::cout << std::endl;
    }

    return 0;
}
