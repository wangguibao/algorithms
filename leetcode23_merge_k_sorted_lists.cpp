/**
 * @file leetcode23_merge_k_sorted_lists.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2023/05/23 21:59
 * @brief https://leetcode.com/problems/merge-k-sorted-lists/
 **/
#include <iostream>
#include <vector>
#include <queue>

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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        std::vector<ListNode*> heads;

        int list_cnt = lists.size();
        heads.resize(list_cnt);

        for (auto i = 0; i < list_cnt; ++i) {
            heads[i] = lists[i];
        }

        std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> q;
        for (auto i = 0; i < list_cnt; ++i) {
            if (heads[i]) {
                q.push(heads[i]);
            }
        }

        ListNode* newhead = nullptr;
        ListNode* p = nullptr;

        while (!q.empty()) {
            auto ele = q.top();
            q.pop();

            if (newhead == nullptr) {
                newhead = ele;
                p = ele;
            } else {
                p->next = ele;
                p = p->next;
            }

            ele = ele->next;
            if (ele) {
                q.push(ele);
            }
        }

        return newhead;
    }

private:
    struct cmp {
        bool operator() (const ListNode* left, const ListNode* right) {
            return left->val > right->val;
        }
    };
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
        std::cout << "Number of lists (negative exits): " << std::endl;
        int n_lists;
        std::cin >> n_lists;

        if (n_lists < 0) {
            return 0;
        }

        std::vector<ListNode*> lists;

        for (int i = 0; i < n_lists; ++i) {
            std::cout << "Number of elements for " << i << "th list (negative exits): " << std::endl;
            int n;
            std::cin >> n;

            if (n < 0) {
                return 0;
            }

            std::cout << n << " sorted integers: ";
            std::vector<int> l;
            int x;
            for (int i = 0; i < n; ++i) {
                std::cin >> x;
                l.push_back(x);
            }
            ListNode* h = create_list_from_vec(l);
            print_list(h);

            lists.push_back(h);
        }

        // To test again nullptr, deliberately push a null list
        lists.push_back(nullptr);

        Solution solution;
        ListNode* result = solution.mergeKLists(lists);

        print_list(result);
    }

    return 0;
}
