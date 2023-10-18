/*
 * leetcode933_number_of_recent_calls.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/16 19:49
 * @brief https://leetcode.com/problems/number-of-recent-calls
 */
#include <iostream>
#include <queue>

bool comp(int left, int right) {
    return left > right;
}

using namespace std;
class RecentCounter {
public:
    RecentCounter() {
    }

    int ping(int t) {
        q.push(t);
        end = t;

        int b = q.front();
        while (end - b > TIMEFRAME) {
            q.pop();
            b = q.front();
        }

        return q.size();
    }

private:
    std::queue<int> q;

    const int TIMEFRAME = 3000;

    int begin = 0;
    int end = 0;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter* obj = new RecentCounter();

    std::cout << obj->ping(5) << std::endl;
    std::cout << obj->ping(1000) << std::endl;
    std::cout << obj->ping(2000) << std::endl;
    std::cout << obj->ping(5000) << std::endl;
    std::cout << obj->ping(5200) << std::endl;
    std::cout << obj->ping(5201) << std::endl;
    std::cout << obj->ping(5205) << std::endl;

    return 0;
}
