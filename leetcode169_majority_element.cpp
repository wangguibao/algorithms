/**
 * @file leetcode169_majority_element.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/27 14:04
 * @brief https://leetcode.com/problems/majority-element/
 *
 * Try solve this problem in linear time and O(1) space.
 * See https://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int cnt = 1;

        size_t len = nums.size();

        for (size_t i = 1; i < len; ++i) {
            if (cnt <= 0) {
                major = nums[i];
                cnt = 1;
            } else {
                if (nums[i] == major) {
                    ++cnt;
                } else {
                    --cnt;
                }
            }
        }

        return major;
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
        auto ret = solution.majorityElement(nums);

        std::cout << ret << std::endl;
    }

    return 0;
}
