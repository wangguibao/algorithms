/**
 * @file leetcode204_count_primes.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/09/06 10:42
 * @brief https://leetcode.com/problems/count-primes/
 *
 **/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Count number of primes using Sieve of Eratosthenes
 */
class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> bits(n + 1);
        for (int i = 0; i <= n; ++i) {
            bits[i] = true;
        }

        for (int i = 2; i * i <= n; ++i) {
            if (bits[i] == true) {
                for (int j = i * i; j <= n; j += i) {
                    bits[j] = false;
                }
            }
        }

        int total = 0;
        for (int i = 2; i < n; ++i) {
            if (bits[i] == true) {
                ++total;
            }
        }

        return total;
    }
};

int main() {
    int n;

    while (1) {
        std::cout << "Input n (Ctrl-C to exit): " << std::endl;
        if (!(std::cin >> n)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.countPrimes(n);

        std::cout << ret << std::endl;
    }

    return 0;
}
