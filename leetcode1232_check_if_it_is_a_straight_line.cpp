/**
 * @file leetcode1232_check_if_it_is_a_straight_line.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/07/04 16:12
 * @brief https://leetcode.com/problems/check-if-it-is-a-straight-line/
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const auto& c = coordinates;
        int length = c.size();
        int b = 0;
        int e = length - 1;

        int x = c[e][0] - c[b][0];
        int y = c[e][1] - c[b][1];

        for (int i = 1; i < e; ++i) {
            int dx = c[i][0] - c[b][0];
            int dy = c[i][1] - c[b][1];

            // If point i stands in the line formed by points b and e, then
            // this equation must be true:
            //  y   dy
            //  - = -
            //  x   dx
            //
            // To deal with divide-by-zero problem, transform the equation a
            // little
            if (y * dx != x * dy) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    while (1) {
        int n = 0;
        std::cout << "Input number of coordinates (Ctrl-C to exit): " << std::endl;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::vector<std::vector<int>> coordinates;
        for (int i = 0; i < n; ++i) {
            std::cout << "x and y for coordinate " << i << std::endl;
            std::vector<int> row;

            int x;
            int y;
            std::cin >> x >> y;
            coordinates.emplace_back(std::vector<int>({x, y}));
        }

        Solution solution;
        bool ret = solution.checkStraightLine(coordinates);
        std::cout << (ret == true ? "true": "false") << std::endl;
    }

    return 0;
}
