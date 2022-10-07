/**
 * @file leetcode71_simplify_path.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/10/07 10:22:42
 * @brief https://leetcode.com/problems/simplify-path/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> st;

        std::string::size_type pos;
        std::string::size_type now = 1;
        while ((pos = path.find('/', now)) != std::string::npos) {
            std::string sub_str = path.substr(now, pos - now);
            if (sub_str.empty() || sub_str == "/" || sub_str == ".") {
            } else if (sub_str == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(sub_str);
            }

            now = pos + 1;
        }

        if (now < path.length()) {
            std::string sub_str = path.substr(now, path.length());
            if (sub_str.empty() || sub_str == "/" || sub_str == ".") {

            } else if (sub_str == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(sub_str);
            }
        }

        std::stack<std::string> st_reverse;

        while (!st.empty()) {
            std::string top = st.top();
            st_reverse.push(top);
            st.pop();
        }

        std::string cananical = "/";
        while (!st_reverse.empty()) {
            cananical += st_reverse.top();
            st_reverse.pop();

            if (!st_reverse.empty()) {
                cananical += '/';
            }
        }

        return cananical;
    }
};

int main() {
    std::string s;

    while (1) {
        std::string path;
        std::cout << "Input path (empty string to exit): ";
        std::getline(std::cin, path);

        if (path.length() == 0) {
            return 0;
        }

        Solution solution;
        auto ret = solution.simplifyPath(path);

        std::cout << ret << std::endl;
    }

    return 0;
}
