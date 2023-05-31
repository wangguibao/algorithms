/**
 * @file leetcode121_best_time_to_buy_and_sell_stock.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/31 13:55
 * @brief https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 **/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t len = prices.size();
        if (len <= 1) {
            return 0;
        }

        int curMin = prices[0];
        int curMax = prices[0];
        int total = 0;

        for (size_t i = 1; i < len; ++i) {
            if (prices[i] < curMin) {
                int profit = curMax - curMin;
                if (profit > total) {
                    total = profit;
                }

                curMin = prices[i];
                curMax = prices[i];
            } else if (prices[i] > curMax) {
                curMax = prices[i];
            }
        }

        int profit = curMax - curMin;
        if (total < profit) {
            total = profit;
        }
        return total;
    }
};

int main() {
    while (1) {
        std::cout << "Number of elements (control-C to exit): ";
        int n = 0;

        if (!(cin >> n)) {
             return -1;
        }

        std::vector<int> prices;
        int x;
        for (size_t i = 0; i < n; ++i) {
            cin >> x;
            prices.emplace_back(x);
        }

        Solution solution;
        auto ret = solution.maxProfit(prices);
        std::cout << ret << std::endl;
    }

    return 0;
}
