/**
 * @file leetcode167_two_sum_ii_input_array_is_sorted.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/25 14:34
 * @brief https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int b = 0;
        int e = numbers.size() - 1;

        while (b < e) {
            int sum = numbers[b] + numbers[e];
            if (sum == target) {
                return std::vector<int>({b + 1, e + 1});
            } else if (sum > target) {
                --e;
            } else {
                ++b;
            }
        }

        return std::vector<int>({0, 0});
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
        auto ret = solution.twoSum(nums, target);

        std::cout << ret[0] << " " << ret[1] << std::endl;
    }

    return 0;
}
