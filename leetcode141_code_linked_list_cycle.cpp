/**
 * @file leetcode141_linked_list_cycle.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2023/06/03 10:42
 * @brief https://leetcode.com/problems/linked-list-cycle
 *
 * Two solutions provided.
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * O(n) space solution
     * When traversing the list, if a node is seen a second time, then there's
     * a cycle.
     */
    bool hasCycle1(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        std::set<ListNode*> nodes;
        ListNode* p = head;

        while (p) {
            if (nodes.find(p) != nodes.end()) {
                return true;
            }
            nodes.insert(p);
            p = p->next;
        }

        return false;
    }

    /*
     * O(1) space solution
     * While traversing the list, if fast pointer catches up with the slow
     * pointer, then there is a cycle
     */
    bool hasCycle2(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* p1 = head;    // The slow pointer
        ListNode* p2 = head;    // The fast pointer

        while (p1 && p2) {
            p1 = p1->next;
            if (!p1) {
                break;
            }

            p2 = p2->next;
            if (!p2) {
                break;
            }

            if (!p2) {
                break;
            }

            p2 = p2->next;
            if (p2 == p1) {
                return true;
            }
        }

        return false;
    }

};

ListNode* createListFromVec(std::vector<int> nums, int tailPos) {
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

    if (tailPos >= 0) {
        ListNode* p = head;
        for (int i = 0; i < tailPos; ++i) {
            p = p->next;
        }

        cur->next = p;
    }

    return head;
}

void printList(ListNode* head, int nodeCount) {
    ListNode* p = head;

    int i = 1;
    std::cout << "[";
    while(p && (i <= nodeCount)) {
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

        if (n <= 0) {
            return 0;
        }

        std::vector<int> l;

        std::cout << "Input " << n << " elements" << std::endl;
        for (int i = 0; i < n; ++i) {
            int ele;
            std::cin >> ele;
            l.push_back(ele);
        }

        std::cout << "Next pointer of tail element index: ";
        int pos;
        std::cin >> pos;

        ListNode* h = createListFromVec(l, pos);
        printList(h, n);

        Solution solution;
        auto result = solution.hasCycle2(h);

        std::cout << (result? "true" : "false") << std::endl;
    }

    return 0;
}
