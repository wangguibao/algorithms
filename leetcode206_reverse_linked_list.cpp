/**
 * @file leetcode206_reverse_linked_list.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2023/06/12 13:52
 * @brief https://leetcode.com/problems/reverse-linked-list/
 */
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* cur = head;
        ListNode* next = cur->next;

        ListNode* newHead = nullptr;
        while (cur) {
            cur->next = newHead;
            newHead = cur;

            cur = next;

            if (next) {
                next = next->next;
            }
        }

        return newHead;
    }
};

ListNode* createListFromVec(std::vector<int> nums) {
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

void printList(ListNode* head) {
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
        if (!(std::cin >> n)) {
            return 0;
        }

        std::vector<int> l;

        std::cout << "Input " << n << " elements" << std::endl;
        for (int i = 0; i < n; ++i) {
            int ele;
            std::cin >> ele;
            l.push_back(ele);
        }
        ListNode* h = createListFromVec(l);
        printList(h);

        Solution solution;
        ListNode* result = solution.reverseList(h);

        printList(result);
    }

    return 0;
}
