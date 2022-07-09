/**
 * @file leetcode42_trapping_rain_water_01_brute_force.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/03 15:20:31
 * @brief https://leetcode.com/problems/trapping-rain-water/
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int trap(std::vector<int>& height) {
        size_t size = height.size();

        int area = 0;
        for (size_t i = 1; i < size; ++i) {
            int left_max = height[i];

            for (size_t j = 0; j < i; ++j) {
                if (left_max < height[j]) {
                    left_max = height[j];
                }
            }

            int right_max = height[i];
            for (size_t j = i + 1; j < size; ++j) {
                if (right_max < height[j]) {
                    right_max = height[j];
                }
            }

            int max = std::min(left_max, right_max);

            if (max > height[i]) {
                area += max - height[i];
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
