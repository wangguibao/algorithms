/**
 * @file leetcode42_trapping_rain_water_02_dp.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/09 18:27:23
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

        std::vector<int> left_max(size);
        std::vector<int> right_max(size);

        left_max[0] = height[0];
        for (size_t i = 1; i < size; ++i) {
            left_max[i] = std::max(left_max[i - 1], height[i]);
        }

        right_max[size - 1] = height[size - 1];
        for (ssize_t i = size - 1 - 1; i >= 0; --i) {
            right_max[i] = std::max(height[i], right_max[i + 1]);
        }

        int area = 0;
        for (size_t i = 0; i < size; ++i) {
            int max = std::min(left_max[i], right_max[i]);
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
