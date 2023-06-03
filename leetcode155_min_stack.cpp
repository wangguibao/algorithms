/**
 * @file leetcode155_min_stack.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/03 12:15
 * @brief https://leetcode.com/problems/min-stack
 *
 **/
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (s.size() == 1) {
            smin.push(val);
        } else if (smin.top() > val) {
            smin.push(val);
        } else {
            smin.push(smin.top());
        }
    }

    void pop() {
        s.pop();
        smin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return smin.top();
    }

private:
    std::stack<int> s;
    std::stack<int> smin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << minStack->top() << std::endl;
    std::cout << minStack->getMin() << std::endl;

    delete minStack;

    return 0;
}
