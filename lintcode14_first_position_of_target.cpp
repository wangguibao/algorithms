/**
 * @file lintcode14_first_position_of_target.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/06/12 16:35:21
 * @brief https://www.lintcode.com/problem/14/
 *
 **/
#include <iostream>
#include <vector>

class Solution {
public:
    int binarySearch(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                if (low == high) {
                    return low;
                }
                else {
                    high = mid;
                }
            }
        }

        return -1;
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

        int target;
        std::cout << "Number to be searched: ";
        std::cin >> target;

        Solution solution;
        int ret = solution.binarySearch(nums, target);

        std::cout << ret << std::endl;
    }

    return 0;
}
