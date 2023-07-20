/**
 * @file leetcode134_gas_station.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/07/20 14:44
 * @brief https://leetcode.com/problems/gas-station
 *
 **/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int stations = gas.size();

        for (int i = 0; i < stations; ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if (total_gas < total_cost) {
            return -1;
        }

        for (int start = 0; start < stations;) {
            int surplus = 0;
            bool ok = true;
            for (int i = 0; i < stations; ++i) {
                int id = (start + i) % stations;
                surplus += gas[id] - cost[id];
                if (surplus < 0) {
                    start = id + 1;
                    ok = false;
                    break;
                }
            }

            if (ok) {
                return start;
            }
        }

        return -1;
    }
};

int main() {

    while (1) {
        int n = 0;
        n = 0;
        std::cout << "Number of elements (Ctrl-C to exit): " << std::endl;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " gas volumes: " << std::endl;
        std::vector<int> gas;
        int ele;
        for (int i = 0; i < n; ++i) {
            std::cin >> ele;
            gas.push_back(ele);
        }

        std::cout << n << " costs: " << std::endl;
        std::vector<int> cost;
        for (int i = 0; i < n; ++i) {
            std::cin >> ele;
            cost.push_back(ele);
        }

        Solution solution;
        auto ret = solution.canCompleteCircuit(gas, cost);

        std::cout << ret << std::endl;
    }

    return 0;
}
