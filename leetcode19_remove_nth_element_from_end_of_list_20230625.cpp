/**
 * leecode19_remove_nth_element_from_list_20230625.cpp
 * @author wangguibao (wang_guibao@163.com)
 * @date 2023/06/25 16:04
 * @brief https://leetcode.com/problems/remove-nth-node-from-end-of-list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode newHead;
        newHead.next = head;

        // Get node count
        ListNode* p = head;
        int cnt = 0;
        while (p) {
            ++cnt;
            p = p->next;
        }

        int skipCnt = cnt - n;

        p = &newHead;
        for (int i = 1; i <= skipCnt; ++i) {
            p = p->next;
        }

        if (p->next) {
            ListNode* n = p->next;
            ListNode* nn = n->next;
            delete n;
            p->next = nn;
        }

        return newHead.next;
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

        std::cout << "Input n" << std::endl;
        int k;
        std::cin >> k;

        auto head = createListFromVector(nums);
        printList(head);

        Solution solution;
        auto ret = solution.removeNthFromEnd(head, k);
        printList(ret);
    }
    return 0;
}
