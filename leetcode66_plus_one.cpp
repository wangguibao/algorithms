/**
 * @file leetcode66_plus_one.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/27 11:24
 * @brief https://leetcode.com/problems/plus-one/
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        size_t len = digits.size();
        std::stack<int> sd;

        int sum = 1 + digits[len - 1];
        int remain = sum % 10;
        int up = sum / 10;
        sd.push(remain);

        for (int i = len - 2; i >= 0; --i) {
            sum = digits[i] + up;
            remain = sum % 10;
            up = sum / 10;
            sd.push(remain);
        }

        if (up > 0) {
            sd.push(up);
        }

        std::vector<int> result;
        while (!sd.empty()) {
            result.push_back(sd.top());
            sd.pop();
        }

        return result;
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
        auto ret = solution.plusOne(nums);

        for (auto i: ret) {
            std::cout << i;
        }
        std::cout << endl;
    }

    return 0;
}
