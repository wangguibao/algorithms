/*
 * leetcode206_reverse_linked_list.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/12 14:50
 * @brief https://leetcode.com/problems/reverse-linked-list
 */
#include <iostream>
#include <vector>

using namespace std;
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
        ListNode pivot;
        ListNode* h = head;

        while (h) {
            ListNode* p = h;
            h = h->next;

            p->next = pivot.next;
            pivot.next = p;

        }


        return pivot.next;
    }
};

ListNode* vecToList(std::vector<int> nums) {
    ListNode pivot;
    ListNode* p = &pivot;

    int len = nums.size();

    for (int i = 0; i < len; ++i) {
        ListNode* node = new ListNode(nums[i]);
        p->next = node;
        p = p->next;
    }

    return pivot.next;
}

void printList(ListNode* l) {
    ListNode* p = l;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }

    std::cout << endl;
}

int main() {
    while (1) {
        std::vector<int> nums;
        int n = 0;

        std::cout << "Number of interges: ";
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " integers: ";
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            nums.push_back(x);
        }

        ListNode* l = vecToList(nums);
        printList(l);

        Solution solution;
        auto ret = solution.reverseList(l);
        printList(ret);
    }

    return 0;
}
