/*
 * leetcode1431-kids-with-the-greatest-number-of-candies.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/12/26 15:00
 * @brief https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        int n = candies.size();

        for (int i = 0; i < n; ++i) {
            if (max < candies[i]) {
                max = candies[i];
            }
        }

        std::vector<bool> results(n);
        for (int i = 0; i < n; ++i) {
            if (candies[i] + extraCandies >= max) {
                results[i] = true;
            } else {
                results[i] = false;
            }
        }

        return results;
    }
};

int main() {
    while (1) {
        std::vector<int> candies;
        int extraCandies;

        int n;
        std::cout << "Input number of candies: ";
        std::cin >> n;

        std::cout << "Input " << n << " integers for candies: ";

        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            candies.push_back(x);
        }

        std::cout << "Input extra candies: ";
        std::cin >> extraCandies;

        Solution solution;
        auto ret = solution.kidsWithCandies(candies, extraCandies);

        for (auto x : ret) {
            std::cout << x << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
