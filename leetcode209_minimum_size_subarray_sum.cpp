/**
 * @file leetcode209_minimum_size_subarray_sum.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/15 16:57
 * @brief https://leetcode.com/problems/minimum-size-subarray-sum
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int b = 0;
        int e = 0;
        int len = nums.size();

        int curSum = nums[0];
        while (e < len) {
            if (curSum < target) {
                ++e;
                if (e >= len) {
                    break;
                }
                curSum += nums[e];
            } else {
                int curLen = e - b + 1;
                if (curLen < minLen) {
                    minLen = curLen;
                }

                curSum -= nums[b];
                ++b;
            }
        }

        while (b < e) {
            curSum -= nums[b];
            if (curSum >= target) {
                int curLen = e - b;
                if (curLen < minLen) {
                    minLen = curLen;
                }
            }
            ++b;
        }

        return (minLen == INT_MAX)? 0: minLen;
    }
};

int main() {
    int n;
    std::vector<int> nums;

    while (1) {
        n = 0;
        std::cout << "Number of elements (Ctrl-C to exit): " << std::endl;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " integers: " << std::endl;
        nums.clear();

        int ele;
        for (int i = 0; i < n; ++i) {
            std::cin >> ele;
            nums.push_back(ele);
        }

        std::cout << "Target: ";
        int target;
        cin >> target;

        Solution solution;
        auto ret = solution.minSubArrayLen(target, nums);

        std::cout << ret << std::endl;
    }

    return 0;
}
