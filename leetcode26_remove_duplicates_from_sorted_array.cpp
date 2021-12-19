/**
 * @file leetcode26_remove_duplicates_from_sorted_array.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2021/12/19 14:56:01
 * @brief
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int idx = 1;
        int cur_value = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != cur_value) {
                nums[idx++] = nums[i];
                cur_value = nums[i];
            }
        }

        return idx;
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
        size_t len = solution.removeDuplicates(nums);

        std::cout << "[";
        for (size_t i = 0; i < len; ++i) {
            std::cout << nums[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
