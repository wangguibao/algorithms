/**
 * @file leetcode1_two_sum.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/26 15:09
 * @brief https://leetcode.com/problems/two-sum/
 *
 **/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;

        if (nums.empty()) {
            return result;
        }

        std::map<int, std::vector<size_t>> m;
        size_t size = nums.size();
        for (size_t i = 0; i < size; ++i) {
            auto iter = m.find(nums[i]);
            if (iter == m.end()) {
                std::vector<size_t> vec{i};
                m.insert({nums[i], vec});
            } else {
                iter->second.push_back(i);
            }
        }

        for (size_t i = 0; i < size; ++i) {
            auto iter = m.find(target - nums[i]);
            if (iter != m.end()) {
                auto& vec = iter->second;
                for (size_t j = 0; j < vec.size(); ++j) {
                    if (vec[j] == i) {
                        continue;
                    }

                    if (vec[j] < i) {
                        result.emplace_back(vec[j]);
                        result.emplace_back(i);
                    } else {
                        result.emplace_back(i);
                        result.emplace_back(vec[j]);
                    }
                    return result;
                }
            }
        }

        return result;
    }
};

int main() {
    while (1) {
        std::cout << "Input element number of the array (control-C to exit): ";
        int n = 0;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << "Input n integers: ";
        int ele;
        std::vector<int> nums;
        for (auto i = 0; i < n; ++i) {
            std::cin >> ele;
            nums.emplace_back(ele);
        }

        std::cout << "Input target: ";
        int target;
        cin >> target;

        Solution solution;
        auto ret = solution.twoSum(nums, target);
        if (ret.size() == 2) {
            std::cout << ret[0] << " " << ret[1] << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }

    return 0;
}
