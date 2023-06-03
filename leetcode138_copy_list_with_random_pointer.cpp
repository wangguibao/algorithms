/**
 * @file leetcode138_copy_list_with_random_pointer.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/03 13:08
 * @brief https://leetcode.com/problems/copy-list-with-random-pointer
 *
 **/
#include <iostream>
#include <vector>
#include <map>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::vector<Node*> nodeVec;

        if (head == nullptr) {
            return nullptr;
        }

        Node* p = head;
        std::map<Node*, int> nodeMap;
        int index = 0;
        while (p) {
            nodeMap.insert({p, index});
            p = p->next;
            ++index;
        }

        Node* newHead = nullptr;
        Node* cur = nullptr;

        p = head;

        std::vector<Node*> newNodeVec;
        std::vector<int> nextVec;

        while (p) {
            Node* node = new Node(p->val);
            if (newHead == nullptr) {
                newHead = node;
                cur = node;
            } else {
                cur->next = node;
                cur = cur->next;
            }
            newNodeVec.emplace_back(node);

            if (p->random) {
                auto iter = nodeMap.find(p->random);
                if (iter != nodeMap.end()) {
                    nextVec.push_back(iter->second);
                } else {
                    nextVec.push_back(-1);
                }
            } else {
                nextVec.push_back(-1);
            }

            p = p->next;
        }

        size_t size = nextVec.size();
        for (size_t i = 0; i < size; ++i) {
            if (nextVec[i] >= 0) {
                newNodeVec[i]->random = newNodeVec[nextVec[i]];
            }
        }

        return newHead;
    }
};

struct NodeInfo {
    int value;
    int random;
};

Node* createListFromVec(std::vector<NodeInfo> nums) {
    Node* head = nullptr;
    Node* cur = nullptr;
    size_t size = nums.size();

    if (size <= 0) {
        return nullptr;
    }

    std::vector<Node*> nodeVec;

    for (auto x: nums) {
        Node* node = new Node(x.value);

        if (head == nullptr) {
            head = node;
            cur = head;
        } else {
            cur->next = node;
            cur = cur->next;
        }

        nodeVec.push_back(node);
    }


    for (size_t i = 0; i < size; ++i) {
        if (nums[i].random >= 0) {
            nodeVec[i]->random = nodeVec[nums[i].random];
        }
    }
    return head;
}

void printListWithRandomPointer(Node* node) {
    Node* p = node;
    while (p) {
        std::cout << p->val << " -> ";
        if (p->random) {
            std::cout << p->random->val;
        } else {
            std::cout << "null";
        }
        std::cout << std::endl;
        p = p->next;
    }
}

int main() {
    std::string s;

    while (1) {
        std::cout << "Number of elements in the list (Ctrl-C to exit): ";
        int n;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " (number, pointer) pairs for the list:" << std::endl;
        std::vector<NodeInfo> vec;
        for (int i = 0; i < n; ++i) {
            int ele;
            int pointer;
            std::cin >> ele >> pointer;
            NodeInfo nodeInfo;
            nodeInfo.value = ele;
            nodeInfo.random = pointer;

            vec.emplace_back(nodeInfo);
        }

        Node* l = createListFromVec(vec);

        printListWithRandomPointer(l);

        std::cout << "================" << std::endl;
        Solution solution;
        auto ret = solution.copyRandomList(l);
        printListWithRandomPointer(ret);
    }

    return 0;
}
