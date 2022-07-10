/**
 * @file leetcode19_remove_nth_node_from_end_of_list.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/09 19:53:07
 * @brief https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 **/
#include <iostream>
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
         * Key notes: add a pivot to avoid corner cases
         */
        ListNode pivot;
        pivot.next = head;
        ListNode* end = &pivot;
        ListNode* prev = &pivot;

        for (size_t i = 0; i <= n && end; ++i) {
            end = end->next;
        }

        while (end) {
            end = end->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return pivot.next;
    }
};

ListNode* convert_vec_to_list(std::vector<int> num) {
    size_t size = num.size();
    if (size == 0) {
        return nullptr;
    }

    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (size_t i = 0; i < size; ++i) {
        ListNode* node = new ListNode(num[i]);
        if (head == nullptr) {
            head = node;
            cur = node;
        } else {
            cur->next = node;
            cur = cur->next;
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
        std::cout << "Number of elements (0 to exit): ";

        size_t n = 0;

        std::cin >> n;

        if (n <= 0) {
            return 0;
        }

        std::cout << n << " integers:" << std::endl;

        std::vector<int> vec;
        int x;
        for (size_t i = 0; i < n; ++i) {
            std::cin >> x;
            vec.push_back(x);
        }

        std::cout << "Positon to remove:";
        int pos = 0;
        std::cin >> pos;

        ListNode* l = convert_vec_to_list(vec);
#if 1
        print_list(l);
#endif
        Solution solution;
        auto ret = solution.removeNthFromEnd(l, pos);
#if 1
        print_list(ret);
#endif
    }

    return 0;
}
