/**
 * @file leetcode31_next_permutation.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2021/12/19 15:23:32
 * @brief https://leetcode.com/problems/next-permutation/
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int left = -1;

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                left = i;
                break;
            }
        }

        int right = 0;
        for (size_t i = nums.size() - 1; i > left; --i) {
            if (nums[i] > nums[left]) {
                right = i;
                std::swap(nums[left], nums[right]);
                break;
            }
        }

        int lo = left + 1;
        int hi = nums.size() - 1;
        while (lo < hi) {
            std::swap(nums[lo], nums[hi]);
            ++lo;
            --hi;
        }
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
        solution.nextPermutation(nums);

        std::cout << "[";
        for (size_t i = 0; i < nums.size(); ++i) {
            std::cout << nums[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
