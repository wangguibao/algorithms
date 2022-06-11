/**
 * @file leetcode33_search_in_roated_sorted_array.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/06/11 17:47:35
 * @brief https://leetcode.com/problems/search-in-rotated-sorted-array/
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
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[low] && nums[mid] > nums[high]) {
                // mid is in first half
                if (target < nums[mid]) {
                    if (target > nums[low]) {
                        high = mid - 1;
                    } else if (target == nums[low]) {
                        return low;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] < nums[low] && nums[mid] < nums[high]) {
                // mid is in second half
                if (nums[low] > nums[high]) {
                    if (target < nums[mid]) {
                        high = mid - 1;
                    } else {
                        if (target > nums[low]) {
                            high = mid - 1;
                        } else if (target == nums[low]) {
                            return low;
                        } else {
                            low = mid + 1;
                        }
                    }
                } else {
                    if (target < nums[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            } else {
                // There's no rotation at all
                if (target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
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
        int ret = solution.search(nums, target);

        std::cout << ret << std::endl;
    }

    return 0;
}
