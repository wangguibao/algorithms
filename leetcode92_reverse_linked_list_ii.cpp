/**
 * @file leetcode92_reverse_linked_list_ii.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2023/06/11 21:39
 * @brief https://leetcode.com/problems/reverse-linked-list-ii
 **/
#include <iostream>
#include <set>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Find last node before the reversed list
        ListNode* tmp = nullptr;
        int i = 0;
        while (i + 1 < left) {
            if (tmp == nullptr) {
                tmp = head;
            } else {
                tmp = tmp->next;
            }
            ++i;
        }

        ListNode* lastNodeBeforeReverse = tmp;

        // Find first node after the reversed list
        while (i < right) {
            if (tmp == nullptr) {
                tmp = head;
            } else {
                tmp = tmp->next;
            }
            ++i;
        }

        ListNode* firstNodeAfterReverse = tmp->next;

        // Reverse the list
        ListNode* node = (lastNodeBeforeReverse? lastNodeBeforeReverse->next : head);
        ListNode* next = node->next;
        ListNode* firstNodeInReversedList = nullptr;
        ListNode* lastNodeInReversedList = nullptr;

        while (node != firstNodeAfterReverse) {
            node->next = firstNodeInReversedList;
            firstNodeInReversedList = node;

            if (lastNodeInReversedList == nullptr) {
                lastNodeInReversedList = node;
            }

            node = next;
            if (next) {
                next = next->next;
            }
        }

        if (lastNodeBeforeReverse) {
            lastNodeBeforeReverse->next = firstNodeInReversedList;
        } else {
            head = firstNodeInReversedList;
        }

        lastNodeInReversedList->next = firstNodeAfterReverse;

        return head;
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

    int i = 1;
    std::cout << "[";
    while(p) {
        std::cout << p->val << " ";
        i++;
        p = p->next;
    };

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

        std::cout << "left and right: " << std::endl;
        int left;
        int right;

        std::cin >> left >> right;

        ListNode* h = createListFromVec(l);
        printList(h);

        Solution solution;
        auto result = solution.reverseBetween(h, left, right);

        printList(result);
    }

    return 0;
}
