/**
 * @file leetcode21_merge_two_sorted_lists.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/03 12:34
 * @brief https://leetcode.com/problems/merge-two-sorted-lists
 *
 **/
#include <iostream>
#include <vector>
#include <string>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        ListNode* head = nullptr;
        ListNode* cur = nullptr;

        while (p1 && p2) {
            ListNode* p = nullptr;
            if (p1->val < p2->val) {
                p = p1;
                p1 = p1->next;
            } else {
                p = p2;
                p2 = p2->next;
            }

            if (head == nullptr) {
                head = p;
                cur = p;
            } else {
                cur->next = p;
                cur = cur->next;
            }
        }

        if (p1) {
            cur->next = p1;
        }

        if (p2) {
            cur->next = p2;
        }

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

void printList(ListNode* node) {
    ListNode* p = node;
    while (p) {
        std::cout << p->val;
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    std::string s;

    while (1) {
        std::cout << "Number of elements in first list (Ctrl-C to exit): ";
        int n1;
        if (!(std::cin >> n1)) {
            return 0;
        }

        std::cout << n1 << " numbers for first list:" << std::endl;
        std::vector<int> vec1;
        for (int i = 0; i < n1; ++i) {
            int ele;
            std::cin >> ele;
            vec1.emplace_back(ele);
        }

        int n2;
        std::cout << "Number of elements in seconde list (Ctrl-C to exit): ";
        if (!(std::cin >> n2)) {
            return 0;
        }

        std::cout << n2 << " numbers for second list:" << std::endl;

        std::vector<int> vec2;
        for (int i = 0; i < n2; ++i) {
            int ele;
            std::cin >> ele;
            vec2.emplace_back(ele);
        }

        ListNode* l1 = createListFromVec(vec1);
        ListNode* l2 = createListFromVec(vec2);

        printList(l1);
        printList(l2);

        Solution solution;
        auto ret = solution.mergeTwoLists(l1, l2);
        printList(ret);

    }

    return 0;
}
