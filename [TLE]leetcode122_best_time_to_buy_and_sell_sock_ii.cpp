/**
 * @file leetcode122_best_time_to_buy_and_sell_stock_ii.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/27 14:36
 * @brief https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 *
 * Note: This backtracking solution is Time Limit Exceeded on leetcode.
 * Better one to be done
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t len = prices.size();
        int max_profit = -INT_MAX;

        for (size_t i = 0; i < len; ++i) {
            int candidate = maxp(prices, i, prices[i]);
            if (candidate > max_profit) {
                max_profit = candidate;
            }
        }

        return (max_profit > 0) ? max_profit: 0;
    }
private:
    int maxp(vector<int>& prices, size_t index, int hold_price) {
        if (index >= prices.size()) {
            return 0;
        }

        int current_max = 0;

        if (hold_price >= 0) {
            // Currently holding stock
            // Try sell
            int profit;
            if (prices[index] > hold_price) {
                profit = prices[index] - hold_price;
                profit += maxp(prices, index+1, -1);
                current_max = profit;
            }

            // Try not sell
            profit = maxp(prices, index+1, hold_price);
            if (current_max < profit) {
                current_max = profit;
            }
        } else {
            // Currently not holding stock
            // Try buy
            int profit = maxp(prices, index+1, prices[index]);
            if (profit > current_max) {
                current_max = profit;
            }

            profit = maxp(prices, index+1, -1);
            if (profit > current_max) {
                current_max = profit;
            }
        }

        return current_max;
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
        auto ret = solution.maxProfit(nums);

        std::cout << ret << std::endl;
    }

    return 0;
}
