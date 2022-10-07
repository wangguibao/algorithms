/**
 * @file leetcode78_subsets.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/10/07 11:27:51
 * @brief https://leetcode.com/problems/subsets/
 *
 **/
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::vector<int> cur_vec;
        dfs(nums, 0, cur_vec, ret);

        return ret;
    }

private:
    void dfs(
            std::vector<int>& nums,
            int index,
            std::vector<int>& cur_vec,
            std::vector<std::vector<int>>& ret) {
        if (index >= nums.size()) {
            return;
        }

        if (index +1 == nums.size()) {
            ret.push_back(cur_vec);

            cur_vec.push_back(nums[index]);
            ret.push_back(cur_vec);
            cur_vec.pop_back();
            return;
        }

        // 1. Don't pick current element
        dfs(nums, index + 1, cur_vec, ret);

        cur_vec.push_back(nums[index]);
        dfs(nums, index + 1, cur_vec, ret);
        cur_vec.pop_back();
    }
};

int main() {
    int n;
    std::vector<int> nums;

    while (1) {
        n = 0;
        std::cout << "Number of elements: ";
        std::cin >> n;
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
        auto ret = solution.subsets(nums);

        std::cout << "[" << std::endl;

        for (auto vec: ret) {
            std::cout << "[";

            for (size_t i = 0; i < vec.size(); ++i) {
                std::cout << vec[i] << " ";
            }

            std::cout << "]" << std::endl;
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
