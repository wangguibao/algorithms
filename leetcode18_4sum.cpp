/**
 * @file leetcode18_4sum.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2021/12/12 14:59:22
 * @brief https://leetcode.com/problems/4sum/
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> ret_arrays;

        if (nums.size() < 4) {
            return ret_arrays;
        }

        std::sort(nums.begin(), nums.end());

        size_t n = nums.size();
        for (size_t i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            long long sum = static_cast<long long int>(nums[i])
                + nums[i + 1]
                + nums[i + 2]
                + nums[i + 3];
            if (sum > target) {
                continue;
            }

            sum = static_cast<long long int>(nums[i])
                + nums[n - 1]
                + nums[n - 2]
                + nums[n - 3];
            if (sum < target) {
                continue;
            }

            for (size_t j = i + 1; j < n - 2; ++j) {
                if ((j > i + 1) && (nums[j] == nums[j - 1])) {
                    continue;
                }

                size_t k = j + 1;
                size_t l = n - 1;
                std::set<int> past;

                while (k < l) {
                    if (past.find(nums[k]) != past.end()) {
                        ++k;
                        continue;
                    }

                    long long sum = static_cast<long long int>(nums[i])
                        + nums[j]
                        + nums[k]
                        + nums[l];
                    if (sum == target) {
                        ret_arrays.push_back({nums[i], nums[j], nums[k], nums[l]});
                        past.insert(nums[k]);
                        --l;
                        ++k;
                    } else if (sum > target) {
                        --l;
                    } else {
                        ++k;
                    }
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

        std::cout << "target: " << std::endl;
        int target;
        std::cin >> target;

        Solution solution;
        std::vector<std::vector<int>> ret_arrays = solution.fourSum(nums, target);

        std::cout << "[";
        for (auto vec: ret_arrays) {
            std::cout << "[";
            for (auto x: vec) {
                std::cout << x << " ";
            }
            std::cout <<"]";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
