/**
 * @file leetcode33_search_in_rotated_sorted_array_impl_2.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/06 11:43:50
 * @brief
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int end = hi;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[0]) {
                if (target < nums[mid]) {
                    if (target < nums[0]) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                } else {
                    lo = mid + 1;
                }
            } else {
                if (nums[lo] > nums[end]) {
                    if (target < nums[mid]) {
                        hi = mid - 1;
                    } else {
                        if (target >= nums[lo]) {
                            hi = mid - 1;
                        } else {
                            lo = mid + 1;
                        }
                    }
                } else {
                    if (target < nums[mid]) {
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
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
        std::cout << "Target value: " << std::endl;
        std::cin >> target;

        Solution solution;
        int pos = solution.search(nums, target);

        std::cout << pos << std::endl;

    }

    return 0;
}
