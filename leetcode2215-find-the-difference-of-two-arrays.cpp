/*
 * leetcode2215-find-the-difference-of-two-arrays.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/09 16:23
 * @brief https://leetcode.com/problems/find-the-difference-of-two-arrays
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::vector<std::vector<int>> retVec;

        std::set<int> s1;
        std::set<int> s2;

        for (auto x: nums1) {
            s1.insert(x);
        }

        for (auto x: nums2) {
            s2.insert(x);
        }

        std::vector<int> vec;
        for (auto x: s1) {
            if (s2.find(x) == s2.end()) {
                vec.push_back(x);
            }
        }
        retVec.push_back(vec);

        vec.clear();

        for (auto x: s2) {
            if (s1.find(x) == s1.end()) {
                vec.push_back(x);
            }
        }

        retVec.push_back(vec);

        return retVec;
    }
};

int main() {
    while (1) {
        std::vector<int> nums1;
        std::vector<int> nums2;

        int n;
        std::cout << "Input number of interges in nums1: ";
        std::cin >> n;

        std::cout << "Input " << n << " integers for nums1: ";

        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            nums1.push_back(x);
        }

        std::cout << "Input number of interges in nums2: ";
        std::cin >> n;

        std::cout << "Input " << n << " integers for nums2: ";

        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            nums2.push_back(x);
        }


        Solution solution;
        std::vector<std::vector<int>> ret = solution.findDifference(nums1, nums2);

        for (auto v : ret) {
            for (auto x: v) {
                std::cout << x << ' ';
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
