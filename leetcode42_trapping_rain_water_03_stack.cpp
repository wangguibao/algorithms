/**
 * @file leetcode42_trapping_rain_water_03_stack.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/09 18:54:52
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
        std::stack<int> st;

        int area = 0;

        st.push(0);
        for (size_t i = 1; i < size; ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) {
                    break;
                }

                int distance = i - st.top() - 1;

                int min = std::min(height[i], height[st.top()]);
                area += (min - height[top]) * distance;
            }

            st.push(i);
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
