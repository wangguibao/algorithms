/**
 * @file leetcode300_longest_increasing_subsequence.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/09 21:02
 * @brief https://leetcode.com/problems/longest-increasing-subsequence
 *
 **/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        size_t len = nums.size();

        std::vector<int> lis(len);

        lis[0] = 1;
        for (size_t i = 1; i < len; ++i) {
            int cur_max = 1;
            for (size_t j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (cur_max < (lis[j] + 1)) {
                        cur_max = (lis[j] + 1);
                    }
                }
            }

            lis[i] = cur_max;
        }

        int m = lis[0];
        for (size_t i = 1; i < len; ++i) {
            if (m < lis[i]) {
                m = lis[i];
            } 
        }

        return m;
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
        size_t len = solution.lengthOfLIS(nums);

        std::cout << len << std::endl;
    }

    return 0;
}
