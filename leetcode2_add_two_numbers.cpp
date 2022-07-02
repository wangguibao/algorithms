/**
 * @file leetcode2_add_two_numbers.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/02 17:45:45
 * @brief https://leetcode.com/problems/add-two-numbers/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
/*
 * Key points: recursion
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }

        if (l2 == nullptr) {
            return l1;
        }

        ListNode* head = nullptr;
        ListNode* cur_node = nullptr;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;

        while (p1 && p2) {
            int sum = p1->val + p2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* new_node = new ListNode(sum);

            if (head == nullptr) {
                head = new_node;
                cur_node = new_node;
            } else {
                cur_node->next = new_node;
                cur_node = new_node;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* remind = p1 ? p1 : p2;
        while (remind) {
            int sum = remind->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* new_node = new ListNode(sum);

            cur_node->next = new_node;
            cur_node = new_node;
            remind = remind->next;
        }

        if (carry) {
            ListNode* new_node = new ListNode(carry);
            cur_node->next = new_node;
            cur_node = new_node;
        }

        return head;
    }
};

ListNode* convert_number_to_list(int num) {
    ListNode* node = new ListNode();
    if (num == 0) {
        node->val = num;
        return node;
    }

    ListNode* head = nullptr;
    ListNode* cur_node = nullptr;
    while (num > 0) {
        int digit = num % 10;
        ListNode* new_node = new ListNode(digit);
        num = num / 10;

        if (head == nullptr) {
            head = new_node;
            cur_node = new_node;
        } else {
            cur_node->next = new_node;
            cur_node = new_node;
        }
    }

    return head;
}

void print_list(ListNode* node) {
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
        std::cout << "Input 2 nums: ";

        int x = 0;
        int y = 0;

        std::cin >> x >> y;

        ListNode* l1 = convert_number_to_list(x);
        ListNode* l2 = convert_number_to_list(y);
#if 1
        print_list(l1);
        print_list(l2);
#endif
        Solution solution;
        auto ret = solution.addTwoNumbers(l1, l2);
#if 1
        print_list(ret);
#endif // 1
    }

    return 0;
}
