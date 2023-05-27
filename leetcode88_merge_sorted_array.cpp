/**
 * @file leetcode88_merge_sorted_array.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/27 11:42
 * @brief https://leetcode.com/problems/merge-sorted-array/
 *
 **/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> nums1_copy(nums1);

        int pos1 = 0;
        int pos2 = 0;
        int cursor = 0;

        while (pos1 < m && pos2 < n) {
            if (nums1_copy[pos1] < nums2[pos2]) {
                nums1[cursor++] = nums1_copy[pos1++];
            } else {
                nums1[cursor++] = nums2[pos2++];
            }
        }

        while (pos1 < m) {
            nums1[cursor++] = nums1_copy[pos1++];
        }

        while (pos2 < n) {
            nums1[cursor++] = nums2[pos2++];
        }
    }
};

int main() {
    std::vector<int> nums1;
    std::vector<int> nums2;

    while (1) {
        int n1 = 0;
        std::cout << "Number of elements for first array: ";
        std::cin >> n1;
        if (n1 < 0) {
            return 0;
        }

        std::cout << n1 << " integers: " << std::endl;
        nums1.clear();

        int ele;
        for (int i = 0; i < n1; ++i) {
            std::cin >> ele;
            nums1.push_back(ele);
        }

        int n2 = 0;
        std::cout << "Number of elements for second array: ";
        std::cin >> n2;
        if (n2 < 0) {
            return 0;
        }

        std::cout << n2 << " integers: " << std::endl;
        nums2.clear();

        for (int i = 0; i < n2; ++i) {
            std::cin >> ele;
            nums2.push_back(ele);
        }

        for (size_t i = 0; i < n2; ++i) {
            nums1.emplace_back(0);
        }
        Solution solution;
        solution.merge(nums1, n1, nums2, n2);

        for (auto ele: nums1) {
            std::cout << ele;
        }
        std::cout << std::endl;
    }

    return 0;
}
