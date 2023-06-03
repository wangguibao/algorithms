/**
 * @file lintcode322_coin_change.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/03 15:14
 * @brief https://leetcode.com/problems/coin-change
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int minChange[amount + 1];

        if (amount == 0) {
            return 0;
        }

        std::sort(coins.begin(), coins.end());

        if (amount < coins[0]) {
            return -1;
        }

        for (int i = 0; i <= amount; ++i) {
            minChange[i] = INT_MAX;
        }

        size_t denomination_types = coins.size();

        for (size_t i = 0; i < denomination_types; ++i) {
            if (coins[i] > amount) {
                break;
            }
            minChange[coins[i]] = 1;
        }

        for (int i = coins[0]; i <= amount; ++i) {
            int currMin = INT_MAX;

            for (size_t j  = 0; j < denomination_types; ++j) {
                int d = i - coins[j];

                if (d < 0) {
                    break;
                } else {
                    if (minChange[d] != INT_MAX) {
                        int minVal = minChange[d] + 1;
                        if (currMin > minVal) {
                            currMin = minVal;
                        }
                    }
                }
            }

            if (minChange[i] > currMin) {
                minChange[i] = currMin;
            }
        }

        if (minChange[amount] == INT_MAX) {
            return -1;
        } else {
            return minChange[amount];
        }
    }
};

int main() {
    int n;
    std::vector<int> denominations;

    while (1) {
        n = 0;
        std::cout << "Number of coin denominations: ";
        std::cin >> n;
        if (n <= 0) {
            return 0;
        }

        std::cout << n << " denominations: " << std::endl;
        denominations.clear();

        int denomination;
        for (int i = 0; i < n; ++i) {
            std::cin >> denomination;
            denominations.push_back(denomination);
        }

        int amount;
        std::cout << "Amount to be matched: ";
        std::cin >> amount;

        Solution solution;
        int ret = solution.coinChange(denominations, amount);

        std::cout << ret << std::endl;
    }

    return 0;
}
