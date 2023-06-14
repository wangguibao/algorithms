/**
 * @file leetcode136_single_number.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/14 19:27
 * @brief https://leetcode.com/problems/single-number/
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t len = nums.size();
        int ret = 0;

        for (size_t i = 0; i < len; ++i) {
            ret ^= nums[i];
        }
        return ret;
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
        auto ret = solution.singleNumber(nums);

        std::cout << ret << std::endl;
    }

    return 0;
}
