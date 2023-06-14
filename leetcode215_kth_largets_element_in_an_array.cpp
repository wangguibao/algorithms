/**
 * @file leetcode215_kth_largest_element_in_an_array.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/14 20:13
 * @brief https://leetcode.com/problems/kth-largest-element-in-an-array/
 **/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        size_t len = nums.size();
        if (len <= 0) {
            return -1;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }

        for (int i = k; i < len; ++i) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

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

        int k;
        std::cout << "Input k:" << std::endl;
        cin >> k;

        Solution solution;
        auto ret = solution.findKthLargest(nums, k);

        std::cout << ret << std::endl;
    }

    return 0;
}
