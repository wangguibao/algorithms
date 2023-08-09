/**
 * @file leetcode46_permutations.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/08/09 19:18
 * @brief https://leetcode.com/problems/permutations/
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> ret;

        permutation(nums, nums.size(), 0, ret);

        return ret;
    }
private:
    void permutation(
            std::vector<int>& nums,
            int size,
            int index,
            std::vector<std::vector<int>>& ret) {
        if (index + 1 == size) {
            ret.push_back(nums);
            return;
        }

        for (int i = index; i < size; ++i) {
            std::swap(nums[index], nums[i]);
            permutation(nums, size, index + 1, ret);
            std::swap(nums[index], nums[i]);
        }
    }
};

int main() {
    int n;
    std::vector<int> nums;

    while (1) {
        n = 0;
        std::cout << "Number of elements (Ctrl-C to exit): " << std::endl;
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

        Solution solution;
        auto permutations = solution.permute(nums);

        for (auto permutation: permutations) {
            for (auto x: permutation) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
