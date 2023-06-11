/**
 * @file leetcode274_h_index.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/11 10:38
 * @brief https://leetcode.com/problems/h-index
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());

        int len = citations.size();

        int citation = -1;
        int paper = 0;
        for (int i = len - 1; i >= 0; --i) {
            citation = citations[i];
            ++paper;
            if (citation < paper) {
                paper--;
                break;
            }
        }

        return paper;
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
        auto ret = solution.hIndex(nums);
        std::cout << ret << std::endl;
    }

    return 0;
}
