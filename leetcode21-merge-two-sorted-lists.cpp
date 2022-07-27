/**
 * @file leetcode21-merge-two-sorted-lists.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2022/07/27 16:40:46
 * @brief https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* p = head;

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }

            p = p->next;
        }

        if (p1) {
            p->next = p1;
        } else if (p2) {
            p->next = p2;
        }

        return head->next;
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
        std::cout << "Number of elements for first list (negative exits): " << std::endl;
        int n;
        std::cin >> n;

        if (n < 0) {
            return 0;
        }

        std::cout << n << " sorted integers: ";
        std::vector<int> l1;
        int x;
        for (size_t i = 0; i < n; ++i) {
            std::cin >> x;
            l1.push_back(x);
        }

        std::cout << "Number of elements for second list (negative exits): " << std::endl;
        std::cin >> n;

        if (n < 0) {
            return 0;
        }

        std::cout << n << " sorted integers: ";
        std::vector<int> l2;
        for (size_t i = 0; i < n; ++i) {
            std::cin >> x;
            l2.push_back(x);
        }

        ListNode* h1 = create_list_from_vec(l1);
        ListNode* h2 = create_list_from_vec(l2);

        print_list(h1);
        print_list(h2);

        Solution solution;
        ListNode* result =  solution.mergeTwoLists(h1, h2);

        print_list(result);
    }

    return 0;
}
