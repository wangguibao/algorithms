/**
 * @file leetcode15_3sum.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2021/12/07 20:46:39
 * @brief
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret_arrays;

        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            size_t j = i + 1;
            size_t k = nums.size() - 1;

            while (j < k) {
                int two_sum = nums[j] + nums[k];
                if (two_sum == (0 - nums[i])) {
                    std::vector<int> pick;
                    pick.push_back(nums[i]);
                    pick.push_back(nums[j]);
                    pick.push_back(nums[k]);
                    ret_arrays.push_back(pick);
                    while ((++j < k) && (nums[j] == nums[j-1])) {}
                    while ((j < --k) && (nums[k] == nums[k+1])) {}
                } else if (two_sum > (0 - nums[i])) {
                    --k;
                } else {
                    ++j;
                }
            }
        }

        return ret_arrays;
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

        std::vector<std::vector<int>> ret_arrays;
        Solution solution;

        ret_arrays = solution.threeSum(nums);

        std::cout << "[";
        for (auto arr: ret_arrays) {
            std::cout << "[";
            for (auto x: arr) {
                std:: cout << x << " ";
            }
            std::cout << "]";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
