/**
 * @file leetcode41_first_missing_positive.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/02 15:19:37
 * @brief https://leetcode.com/problems/first-missing-positive/description/
 *
 **/
#include <iostream>
#include <vector>
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        size_t nums_size = nums.size();

        /*
         * Key point: only need check again first nums_size integers.
         * The principle:
         * If the vector `nums` has no hole at all, then every one of the first
         * `nums_size` integers must be in it, so return nums_size + 1;
         * on the other hand, if there is a hole, then the hole (the missed integer)
         * must be in the first `nums_size` integers.
         *
         */

        std::vector<bool> nums_set_vec(nums.size() + 1);
        for (auto x: nums) {
            if (x < 0) {
                continue;
            }

            if (x > nums.size()) {
                continue;
            }

            nums_set_vec[x] = true;
        }

        for (size_t i = 1; i <= nums_size; ++i) {
            if (!nums_set_vec[i]) {
                return i;
            }
        }

        return nums_size + 1;
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
        int ret = solution.firstMissingPositive(nums);

        std::cout << ret << std::endl;
    }

    return 0;
}
