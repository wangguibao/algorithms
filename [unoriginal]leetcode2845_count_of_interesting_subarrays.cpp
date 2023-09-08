/**
 * @file leetcode2845_count_of_interesting_subarrays.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/09/08 17:38
 * @brief https://leetcode.com/problems/count-of-interesting-subarrays/
 *
 **/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    /*
     * Solution:
     * https://leetcode.com/problems/count-of-interesting-subarrays/solutions/3995124/c-count-subarrays-with-sum-mod-k-easy-explanation/
     */
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int len = nums.size();

        std::vector<bool> flag(len, false);
        std::map<int, uint64_t> mp;
        int n = 0;
        uint64_t total = 0;

        for (int i = 0; i < len; ++i) {
            if (nums[i] % modulo == k) {
                flag[i] = true;
                ++n;
            }

            int mod = n % modulo;
            if (mod == k) {
                total++;
            }

            int find = mod - k;
            if (find < 0) {
                find += modulo;
            }

            total += mp[find];

            mp[mod]++;
        }

        return total;
    }
};

int main() {
    while (1) {
        int n = 0;
        std::vector<int> nums;

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

        int modulo = 0;
        std::cout << "Input modulo (Ctrl-C to exit: " << std::endl;
        if (!(std::cin >> modulo)) {
            return 0;
        }

        int k = 0;
        std::cout << "Input k (Ctrl-C to exit): " << std::endl;
        if (!(std::cin >> k)) {
            return 0;
        }

        Solution solution;
        auto ret = solution.countInterestingSubarrays(nums, modulo, k);

        std::cout << ret << std::endl;
    }

    return 0;
}
