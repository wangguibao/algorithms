/**
 * @file leetcode55_jump_game.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/29 20:16
 * @brief https://leetcode.com/problems/jump-game/
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t len = nums.size();
        if (len <= 0) {
            return true;
        }

        std::vector<bool> reachable(len, false);
        reachable[len - 1] = true;

        for (ssize_t i = len - 2; i >= 0; --i) {
            for (int j = 1; j <= nums[i] && (i + j) < len; ++j) {
                if (reachable[i + j]) {
                    reachable[i] = true;
                    break;
                }
            }
        }

        return reachable[0];
    }
};

int main() {
    int n;
    std::vector<int> nums;

    while (1) {
        n = 0;
        std::cout << "Number of elements (Ctrl-C to exit): ";
        std::cin >> n;

        if (!cin >> n) {
            return 0;
        }

        if (n < 0) {
            return 0;
        }

        std::cout << n << " integers: " << std::endl;
        nums.clear();

        int ele;
        for (int i = 0; i < n; ++i) {
            std::cin >> ele;
            nums.push_back(ele);
        }

        Solution solution;
        auto ret = solution.canJump(nums);

        std::cout << (ret ? "true": "false") << std::endl;
    }

    return 0;
}
