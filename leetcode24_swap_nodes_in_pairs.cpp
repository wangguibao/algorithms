/**
 * @file leecode24_swap_nodes_in_pairs.cpp
 * @author wangguibao (wang_guibao@163.com)
 * @date 2023/07/04 14:04
 * @brief https://leetcode.com/problems/swap-nodes-in-pairs
 *
 * Pointer-to-pointer solution from StefanPochmann@leetcode (https://leetcode.com/StefanPochmann/)
 * See https://leetcode.com/problems/swap-nodes-in-pairs/solutions/11019/7-8-lines-c-python-ruby/
 */
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
    ListNode* swapPairs(ListNode* head) {
        ListNode** p = &head;
        ListNode* a = nullptr;
        ListNode* b = nullptr;

        while ((a = *p) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *p = b;

            p = &a->next;
        }

        return head;
    }
};

ListNode* createListFromVector(std::vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;

    for (auto ele: nums) {
        ListNode* node = new ListNode(ele, nullptr);

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

void printList(ListNode* head) {
    ListNode* p = head;
    bool first = true;

    while (p) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << p->val;
        p = p->next;
    }

    std::cout << std::endl;
}

int main()
{
    while (1) {
        std::cout << "Number of elements (Ctrl-C to exit):" << std::endl;
        int n;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " integers: " << std::endl;
        std::vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int ele;
            std::cin >> ele;
            nums.emplace_back(ele);
        }

        auto head = createListFromVector(nums);
        printList(head);

        Solution solution;
        auto ret = solution.swapPairs(head);
        printList(ret);
    }
    return 0;
}
