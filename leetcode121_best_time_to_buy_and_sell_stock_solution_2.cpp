/*
 * leetcode121_best_time_to_buy_and_sell_stock_solution_2.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2024/01/10 19:41
 * @brief https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        int max = -INT_MAX;
        int min = INT_MAX;

        int ret = 0;

        for (int i = 0; i < len; ++i) {
            if (min > prices[i]) {
                min = prices[i];
                max = min;
            }

            if (max < prices[i]) {
                max = prices[i];
                int curMaxProfit = max - min;
                if (ret < curMaxProfit) {
                    ret  = curMaxProfit;
                }
            }
        }

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
