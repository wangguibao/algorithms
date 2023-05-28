/**
 * @file leetcode55_jump_game.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/28 15:55
 * @brief https://leetcode.com/problems/jump-game/
 *
 * NOTE: Although correct, both the backtrack and DP solution is TLE on leetcode.
 * Better solution needs to be done.
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canJump_backtrack(vector<int>& nums) {
        size_t len = nums.size();

        return backtrack(nums, len, 0);
    }

    bool canJump_dp(vector<int>& nums) {
        size_t len = nums.size();

        std::vector<std::vector<bool>> reachable;
        reachable.resize(len);
        for (size_t i = 0; i < len; ++i) {
            reachable[i].resize(len);
            for (int j = 0; j <= nums[i] && (i + j < len); ++j) {
                reachable[i][i + j] = true;
            }
        }

        for (size_t i = 1; i < len; ++i) {
            for (size_t j = 1; j < i; ++j) {
                if (reachable[0][j] && reachable[j][i]) {
                    reachable[0][i] = true;
                }
            }
        }

        return reachable[0][len - 1];
    }

private:
    bool backtrack(vector<int>& nums, int len, int index) {
        if (index+1 >= len) {
            return true;
        }

        for (int i = nums[index]; i >= 1; --i) {
            if (backtrack(nums, len, index + i)) {
                return true;
            }
        }

        return false;
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

        if (n <= 0) {
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
        auto ret = solution.canJump_dp(nums);

        std::cout << (ret ? "true": "false") << std::endl;
    }

    return 0;
}
