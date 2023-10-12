/*
 * leetcode643_maximum_average_subarray_i.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/12 14:37
 * @brief https://leetcode.com/problems/maximum-average-subarray-i
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();

        int sum = 0;
        double maxAverage = 0;

        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        maxAverage = (double)sum / (double)k;

        for (int i = k; i < len; ++i) {
            sum -= nums[i - k];
            sum += nums[i];
            double curAverage = (double)sum / (double)k;

            if (curAverage > maxAverage) {
                maxAverage = curAverage;
            }
        }

        return maxAverage;
    }
};

int main() {
    while (1) {
        std::vector<int> nums;
        int n = 0;

        std::cout << "Number of interges: ";
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " integers: ";
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            nums.push_back(x);
        }

        int k;
        std::cout << "k: ";
        std::cin >> k;

        Solution solution;
        auto ret = solution.findMaxAverage(nums, k);
        std::cout << ret << std::endl;
    }

    return 0;
}
