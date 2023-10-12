/*
 * leetcode2095_delete_the_middle_node_of_a_list.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/12 15:08
 * @brief https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;

        ListNode* p = head;
        while (p) {
            ++n;
            p = p->next;
        }

        int middle = n / 2;
        if (middle <= 0) {
            return nullptr;
        }

        p = head;
        int step = middle - 1;

        while (step) {
            p = p->next;
            --step;
        }

        if (p->next) {
            p->next = p->next->next;
        }


        return head;
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
        auto ret = solution.deleteMiddle(l);
        printList(ret);
    }

    return 0;
}
