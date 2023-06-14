/**
 * @file leetcode33_search_in_rotated_sorted_array.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/14 23:25
 * @brief https://leetcode.com/problems/search-in-rotated-sorted-array/
 **/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b = 0;
        int e = nums.size() - 1;
        int last = e;

        while (b <= e) {
            int mid = (b + e) / 2;
            if (nums[mid] == target) {
                return mid;
            } else {
                if (nums[b] < nums[e]) {
                    if (target > nums[mid]) {
                        b = mid + 1;
                    } else {
                        e = mid - 1;
                    }
                } else {
                    if (nums[mid] >= nums[0]) {
                        // We are in first half
                        if (target > nums[mid]) {
                            b = mid + 1;
                        } else {
                            if (target >= nums[b]) {
                                e = mid - 1;
                            } else {
                                b = mid + 1;
                            }
                        }
                    } else {
                        if (target > nums[mid]) {
                            if (target >= nums[b]) {
                                e = mid - 1;
                            } else {
                                b = mid + 1;
                            }
                        } else {
                            e = mid - 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};

void rotate(std::vector<int>& nums, int r) {
    size_t len = nums.size();

    if (len <= 0) {
        return;
    }

    r %= len;

    auto it = nums.begin();
    std::vector<int> firstPart(it, it + r);
    std::vector<int> secondPart(it + r, nums.end());

    nums = secondPart;
    nums.insert(nums.end(), firstPart.begin(), firstPart.end());

    return;
}

int main() {
    int n;
    std::vector<int> nums;

    while (1) {
        n = 0;
        std::cout << "Number of elements (Ctrl-C to exit): ";
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

#if 0
        std::sort(nums.begin(), nums.end());
        int r = std::rand() % n;
        rotate(nums, r);
#endif
        std::cout << "[";
        for (size_t i = 0; i < n; ++i) {
            std::cout << nums[i] << ",";
        }
        std::cout << "]" << std::endl;

        int k;
        std::cout << "Input target:" << std::endl;
        cin >> k;

        Solution solution;
        auto ret = solution.search(nums, k);

        std::cout << ret << std::endl;
    }

    return 0;
}
