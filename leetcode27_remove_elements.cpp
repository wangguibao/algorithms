/**
 * @file leetcode27_remove_elements.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2021/12/19 15:23:32
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
    int removeElements(std::vector<int>& nums, int val) {
        int idx = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[idx++] = nums[i];
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

        int value;
        std::cout << "Target value: " << std::endl;
        std::cin >> value;

        Solution solution;
        size_t len = solution.removeElements(nums, value);

        std::cout << "[";
        for (size_t i = 0; i < len; ++i) {
            std::cout << nums[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
