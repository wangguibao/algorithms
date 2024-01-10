/*
 * leetcode122_best_time_to_buy_and_sell_stock_ii.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2024/01/10 19:55
 * @brief https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        int ret = 0;

        int min = prices[0];
        int max = min;
        for (int i = 1; i < len; ++i) {
            if (prices[i] < prices[i - 1]) {
                ret += max - min;
                min = prices[i];
                max = min;
            } else if (max < prices[i]) {
                max = prices[i];
            }
        }

        ret += max - min;
        return ret;
    }
};

int main() {
    while (1) {
        std::vector<int> prices;
        int n = 0;

        std::cout << "Number of prices: ";
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " integers: ";
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            prices.push_back(x);
        }

        Solution solution;
        auto ret = solution.maxProfit(prices);
        std::cout << ret << std::endl;
    }

    return 0;
}
