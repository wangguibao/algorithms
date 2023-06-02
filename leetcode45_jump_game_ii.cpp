/**
 * @file leetcode45_jump_game_ii.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/02 14:02
 * @brief https://leetcode.com/problems/jump-game-ii/
 *
 **/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();

        if (len <= 1) {
            return 0;
        }

        std::vector<bool> reachable(len, false);
        std::vector<int> steps(len, INT_MAX);

        reachable[len - 1] = true;
        steps[len - 1] = 0;

        for (int i = len - 2; i >= 0; --i) {
            int step = nums[i];
            int minStep = INT_MAX;

            for (int j = 0; j <= step && (i + j < len); ++j) {
                if (reachable[i + j]) {
                    reachable[i] = true;
                    if (minStep > (steps[i + j] + 1)) {
                        minStep = (steps[i + j] + 1);
                    }
                }
            }

            if (reachable[i]) {
                steps[i] = minStep;
            }
        }

        if (steps[0] < INT_MAX) {
            return steps[0];
        } else {
            return 0;
        }
    }
};

int main() {
    while (1) {
        std::cout << "Number of elements (control-C to exit): ";
        int n = 0;

        if (!(cin >> n)) {
             return -1;
        }

        std::cout << n << " integers" << std::endl;

        std::vector<int> nums;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            nums.emplace_back(x);
        }

        Solution solution;
        auto ret = solution.jump(nums);
        std::cout << ret << std::endl;
    }

    return 0;
}
