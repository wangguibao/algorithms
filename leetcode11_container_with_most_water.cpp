/**
 * @file leetcode11_container_with_most_water.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/02 17:29:15
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
    int maxArea(std::vector<int>& height) {
        size_t begin = 0;
        size_t end = height.size() - 1;
        size_t max_area = 0;

        while (begin <= end) {
            size_t min_height = std::min(height[begin], height[end]);
            size_t area = min_height * (end - begin);

            if (max_area < area) {
                max_area = area;
            }

            if (height[begin] <= height[end]) {
                ++begin;
            } else {
                --end;
            }
        }

        return max_area;
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
        auto ret = solution.maxArea(nums);

        std::cout << ret << std::endl;
    }

    return 0;
}
