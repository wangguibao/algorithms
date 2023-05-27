/**
 * @file leetcode189_rotate_array.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/27 14:36
 * @brief https://leetcode.com/problems/rotate-array/
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t len = nums.size();
        k %= len;

        auto b = nums.begin();
        auto e = b + (len - k);

        std::vector<int> vec1(b, e);
        std::vector<int> vec2(e, nums.end());

        int i = 0;
        for (auto x: vec2) {
            nums[i++] = x;
        }

        for (auto x: vec1) {
            nums[i++] = x;
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

        std::cout << "Rotate: ";
        int k;
        cin >> k;

        Solution solution;
        solution.rotate(nums, k);

        for (auto e: nums) {
            std::cout << e;
        }
        std::cout << std::endl;
    }

    return 0;
}
