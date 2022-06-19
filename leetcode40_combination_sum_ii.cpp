/**
 * @file leetcode40_combination_sum_ii.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/06/19 17:12:00
 * @brief https://leetcode.com/problems/combination-sum-ii/
 *
 **/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
/*
 * Key points: recursion
 */
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> combinations;

        std::sort(candidates.begin(), candidates.end());

        std::vector<int> combination;
        solve(candidates, target, 0, combination, combinations);

        return combinations;
    }

private:
    void solve(
            std::vector<int>& candidates,
            int target,
            int current_index,
            std::vector<int>& combination,
            std::vector<std::vector<int>>& combinations) {
        size_t candidates_size = candidates.size();

        for (size_t i = current_index; i < candidates_size; ++i) {
            if (i > current_index && (candidates[i] == candidates[i - 1])) {
                continue;
            }
            int remain = target - candidates[i];
            if (remain == 0) {
                combination.push_back(candidates[i]);
                combinations.push_back(combination);
                combination.pop_back();
            }
            else if (remain < 0) {
                break;
            }
            else {
                combination.push_back(candidates[i]);
                solve(candidates, remain, i + 1, combination, combinations);
                combination.pop_back();
            }
        }
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

        int target;
        std::cout << "Number to be searched: ";
        std::cin >> target;

        Solution solution;
        std::vector<std::vector<int>> ret = solution.combinationSum(nums, target);

        std::cout << "[";
        for (size_t i = 0; i < ret.size(); ++i) {
            std::cout << "[";
            auto& combination = ret[i];

            for (size_t j = 0; j < combination.size(); ++j) {
                if (j == combination.size() - 1) {
                    std::cout << combination[j];
                }
                else {
                    std::cout << combination[j] << " ";
                }
            }
            std::cout << "]";
        }
        std::cout << "]\n";
    }

    return 0;
}
