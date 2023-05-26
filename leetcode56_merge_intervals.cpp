/**
 * @file leetcode56_merge_intervals.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/26 13:56
 * @brief https://leetcode.com/problems/merge-intervals
 *
 **/    
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),
                intervals.end(),
                [] (std::vector<int>& left, std::vector<int>& right) {return left[0] < right[0];});

        std::vector<std::vector<int>> result;
        int size = intervals.size();
        if (size <= 0) {
            return result;
        }

        int min = intervals[0].at(0);
        int max = intervals[0].at(1);

        for (size_t i = 1; i < size; ++i) {
            if (intervals[i].at(0) > max) {
                std::vector interval{min, max};
                result.emplace_back(interval);
                min = intervals[i].at(0);
                max = intervals[i].at(1);
            } else {
                if (intervals[i].at(0) < min) {
                    min = intervals[i].at(0);
                }
                if (intervals[i].at(1) > max) {
                    max = intervals[i].at(1);
                }
            }
        }

        if (intervals[size - 1].at(0) < min) {
            min = intervals[size - 1].at(0);
        }

        if (intervals[size - 1].at(1) > max) {
            max = intervals[size - 1].at(1);
        }

        std::vector<int> last {min, max};
        result.emplace_back(last);
        return result;  
    }
};

int main() {
    Solution solution;

    while (1) {
        std::cout << "Number of intervals: (Ctrl-C to exit): ";
        
        int interval_cnt;
        if (!(std::cin >> interval_cnt)) {
            return 0;
        }

        if (interval_cnt <= 0) {
            continue;
        }

        std::vector<std::vector<int>> intervals;

    std::cout << interval_cnt << " intervals: ";
        for (auto i = 0; i < interval_cnt; ++i) {
            int b;
            int e;
        std::cin >> b >> e;
        std::vector interval {b, e};

            intervals.emplace_back(interval);
        }

    for (auto v: intervals) {
        std::cout << v[0] << " - " << v[1] << std::endl;
    }

    std::cout << "=========" << std::endl;

        auto ret = solution.merge(intervals);

        for (auto v: ret) {
            std::cout << v[0] << " - " << v[1] << std::endl;
        }
    }

    return 0;
}
