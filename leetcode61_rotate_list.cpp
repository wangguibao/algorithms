/**
 * @file leetcode61_roate_list.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2023/05/23 19:59\
 * @brief https://leetcode.com/problems/rotate-list/
 **/
#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        if (k == 0) {
            return head;
        }

        int n = 0;
        ListNode* p = head;

        while (p) {
            ++n;
            p = p->next;
        }

        if (k >= n) {
            k = k % n;
        }

        if (k == 0) {
            return head;
        }

        p = head;
        auto diff = n - k;
        auto go_cnt = diff - 1;
        while (go_cnt > 0) {
            p = p->next;
            --go_cnt;
        }

        ListNode* newhead = p->next;
        p->next = nullptr;

        p = newhead;
        while (p->next) {
            p = p->next;
        }

        p->next = head;
        return newhead;
    }
};

ListNode* create_list_from_vec(std::vector<int> nums) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;

    for (auto x: nums) {
        ListNode* node = new ListNode(x);

        if (head == nullptr) {
            head = node;
            cur = head;
        } else {
            cur->next = node;
            cur = cur->next;
        }
    }

    return head;
}

void print_list(ListNode* head) {
    ListNode* p = head;

    std::cout << "[";
    while(p) {
        std::cout << p->val << " ";
        p = p->next;
    }

    std::cout << "]" << std::endl;
}

int main() {
    while (1) {
        std::cout << "Number of elements (0 or negative exits): " << std::endl;
        int n;
        std::cin >> n;

        if (n <= 0) {
            return 0;
        }

        std::vector<int> l;

        std::cout << "Input " << n << " elements" << std::endl;
        for (int i = 0; i < n; ++i) {
            int ele;
            std::cin >> ele;
            l.push_back(ele);
        }
        ListNode* h = create_list_from_vec(l);
        print_list(h);

        std::cout << "Number of rotates: " << std::endl;
        int k;
        std::cin >> k;

        Solution solution;
        ListNode* result = solution.rotateRight(h, k);

        print_list(result);
    }

    return 0;
}