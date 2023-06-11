/**
 * @file leetcode77_combinations.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/11 10:11
 * @brief https://leetcode.com/problems/combinations
 *
 **/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<int> comb;
        std::vector<std::vector<int>> retVec;

        for (int i = 1; i <= n; ++i) {
            comb.clear();
            backtrack(n, i, k, comb, retVec);
        }

        return retVec;
    }

private:
    void backtrack(
            int n,
            int i,
            int k,
            std::vector<int>& comb,
            std::vector<std::vector<int>>& retVec) {
        if (i > n) {
            return;
        }

        comb.push_back(i);

        if (comb.size() == k) {
            retVec.push_back(comb);
            comb.pop_back();
            return;
        }

        for (int j = i + 1; j <= n; ++j) {
            backtrack(n, j, k, comb, retVec);
        }
        comb.pop_back();
    }
};

int main() {
    while (1) {
        std::cout << "Input n and k (control-C to exit): ";
        int n = 0;
        int k = 0;

        if (!(std::cin >> n >> k)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.combine(n, k);

        for (auto vec: ret) {
            std::cout << "[";
            for (auto ele: vec) {
                std::cout << ele << " ";
            }

            std::cout << "]" << std::endl;
        }
    }

    return 0;
}
