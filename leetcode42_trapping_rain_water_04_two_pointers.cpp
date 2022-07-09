/**
 * @file leetcode42_trapping_rain_water_04_two_pointers.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/09 19:35:57
 * @brief https://leetcode.com/problems/trapping-rain-water/
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = height[0];
        int right_max = height[right];

        int area = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (left_max >= height[left]) {
                    area += left_max - height[left];
                } else {
                    left_max = height[left];
                }

                ++left;
            } else {
                if (right_max >= height[right]) {
                    area += right_max - height[right];
                } else {
                    right_max = height[right];
                }

                --right;
            }
        }
        return area;
    }
};

int main() {
    size_t n;
    std::vector<int> height;

    while (1) {
        n = 0;
        std::cout << "Number of elements: ";
        std::cin >> n;
        if (n <= 0) {
            return 0;
        }

        std::cout << n << " integers: " << std::endl;
        height.clear();

        for (size_t i = 0; i < n; ++i) {
            int number;
            std::cin >> number;
            height.push_back(number);
        }

        Solution solution;
        size_t area = solution.trap(height);

        std::cout << area << std::endl;
    }

    return 0;
}
