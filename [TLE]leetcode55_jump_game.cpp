/**
 * @file leetcode55_jump_game.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/28 15:55
 * @brief https://leetcode.com/problems/jump-game/
 *
 * NOTE: Although correct, this backtrack algorithm is TLE on leetcode.
 * Better solution needs to be done.
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t len = nums.size();

        return backtrack(nums, len, 0);
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
        auto ret = solution.canJump(nums);

        std::cout << (ret ? "true": "false") << std::endl;
    }

    return 0;
}
