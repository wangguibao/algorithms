/**
 * @file leetcode16_3sum_closest.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2021/12/10 10:42:27
 * @brief https://leetcode.com/problems/3sum-closest/
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        if (nums.size() < 3) {
            int sum = 0;
            for (auto x: nums) {
                sum += x;
            }
            return sum;
        }

        uint32_t diff = UINT_MAX;
        std::sort(nums.begin(), nums.end());
        int res = 0;

        for (size_t i = 0; i < nums.size() - 2; ++i) {
            size_t j = i + 1;
            size_t k = nums.size() - 1;

            while (j < k) {
                int sum = nums[j] + nums[k] + nums[i];

                if (std::abs(sum - target) < diff) {
                    res = sum;
                    diff = std::abs(sum - target);
                }

                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }

        return res;
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

        std::cout << "target: " << std::endl;
        int target;
        std::cin >> target;

        Solution solution;
        std::cout << solution.threeSumClosest(nums, target) << std::endl;
    }

    return 0;
}
