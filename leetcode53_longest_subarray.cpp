/**
 * @file leetcode53_longest_subarray.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/31 19:57:36
 * @brief https://leetcode.com/problems/maximum-subarray/
 *
 **/
#include <iostream>
#include <vector>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        /*
         * Many people resolve this problem in DP way. While my algothm is
         * almost the same, I see the problem in a different way.
         *
         * It' more like a running sum approach: keep going along the list,
         * adding the new element to the sum, at the same time update the max
         * sum. As long as the running sum is positive, keep go this way. Once
         * we see a point where the sum drops below 0, we stop here and start
         * a new running sum. This is because, adding next element to a negative
         * sum will not get a larger sum.
         *
         * See we have an array A[0:N], and the first part A[0:i] has a negative
         * running sum. Now we see what happens if we add A[i + 1] to the running
         * sum:
         *
         *       A[0, 1, ...i,     i+1, ... N]
         *     sum[0, 1, ...i] + A[i+1]
         *        \-negative-/
         *
         * case 1) A[i+1] > 0, then
         *     sum[0,...i] + A[i+1] < A[i+1]
         *   meaning adding A[i+1] will not get larger sum than A[i+1] along
         *
         * case 2) A[i+1] < 0, then
         *     sum[0,...i] + A[i+1] < sum[0,...i]
         *   meaning adding A[i+1] will not get larger sum than previous running sum.
         *
         * In either case, there is no hope we can find larger sum in adding A[i+1]
         * to the previous running sum
         */
        int max_sum = INT_MIN;

        int sum = 0;

        size_t len = nums.size();

        for (size_t i = 0; i < len; ++i) {
            sum += nums[i];
            if (max_sum < sum) {
                max_sum = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return max_sum;
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
        int ret = solution.maxSubArray(nums);

        std::cout << ret << std::endl;
    }

    return 0;
}
