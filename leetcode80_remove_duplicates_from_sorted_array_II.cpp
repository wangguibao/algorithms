/**
 * @file leetcode80_remove_duplicates_from_sorted_array_ii.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/27 13:10
 * @brief https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t len = nums.size();

        int cur_dup = 1;
        int write_index = 1;
        int cur_value = nums[0];

        for (size_t i = 1; i < len; ++i) {
            if (nums[i] != cur_value) {
                cur_dup = 1;
                cur_value = nums[i];
                nums[write_index++] = nums[i];
            } else {
                ++cur_dup;
                if (cur_dup <= 2) {
                    nums[write_index++] = nums[i];
                }
            }
        }
        return write_index;
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
        auto ret = solution.removeDuplicates(nums);

        for (auto i = 0; i < ret; ++i) {
            std::cout << nums[i] << ' ';
        }
        std::cout << endl;
    }

    return 0;
}
