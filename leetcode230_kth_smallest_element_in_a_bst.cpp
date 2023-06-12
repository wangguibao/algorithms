/**
 * @file leetcode230_kth_smallest_element_in_bst.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/12 14:52
 * @brief https://leetcode.com/problems/kth-smallest-element-in-a-bst
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret;
        bool found = false;
        inOrderTraversal(root, k, ret, found);

        if (!found) {
            return -1;
        }

        return ret;
    }

private:
    void inOrderTraversal(TreeNode* root, int& k, int& ret, bool& found) {
        if (root == nullptr) {
            return;
        }

        if (found) {
            return;
        }

        if (root->left) {
            inOrderTraversal(root->left, k, ret, found);
        }
        
        --k;
        if (k == 0) {
            ret = root->val;
            found = true;
            return;
        }

        if (root->right) {
            inOrderTraversal(root->right, k, ret, found);
        }
    }
};

TreeNode* createBinarySearchTreeFromSortedVec(std::vector<int> nums, int begin, int end) {
    if (nums.empty()) {
        return nullptr;
    }

    if (begin > end) {
        return nullptr;
    }

    int mid = (begin + end) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = createBinarySearchTreeFromSortedVec(nums, begin, mid - 1);
    node->right = createBinarySearchTreeFromSortedVec(nums, mid + 1, end);
    return node;
}

int treeLevel(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftLevel = treeLevel(root->left);
    int rightLevel = treeLevel(root->right);
    return std::max(leftLevel, rightLevel) + 1;
}

int getDigits(int x) {
    int ab = abs(x);
    int digits = 0;

    if (ab < 10) {
        digits = 1;
    } else if (ab < 100) {
        digits = 2;
    } else if (digits < 1000) {
        digits = 3;
    } else if (digits < 10000) {
        digits = 4;
    }

    if (x < 0) {
        digits++;
    }
    return digits;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    int levels = treeLevel(root);

    struct NodeInfo {
        TreeNode* node = nullptr;
        int level = -1;
    };

    std::queue<NodeInfo> q;
    NodeInfo info;
    info.node = root;
    info.level = 0;

    q.push(info);

    int level = -1;

    while (!q.empty()) {
        auto info = q.front();
        q.pop();

        if (info.level != level) {
            int spacesAfter = pow(2, levels - level - 2) - 1;

            for (int i = 0; i < spacesAfter; ++i) {
                std::cout << " ";
            }
            std::cout << std::endl;

            int spacesBefore = pow(2, levels - level - 2) - 1;
            for (int i = 0; i < spacesBefore; ++i) {
                std::cout << " ";
            }

            level = info.level;
        }

        if (info.node) {
            std::cout << info.node->val;
        } else {
            std::cout << "_";
        }

        int spacesBetween = pow(2, levels - level) - 1;

        // Save spaces for next digit
        int digits = 0;
        if (!q.empty()) {
            auto nextInfo = q.front();
            if (nextInfo.node) {
                digits = getDigits(nextInfo.node->val);
            } else {
                digits = 1;
            }
        }

        spacesBetween -= digits - 1;
        if (spacesBetween < 0) {
            spacesBetween = 0;
        }

        for (int i = 0; i < spacesBetween; ++i) {
            std::cout << " ";
        }

        if (info.node) {
            NodeInfo child;
            if (info.node->left) {
                child.node = info.node->left;
            }
            child.level = info.level + 1;
            q.push(child);

            if (info.node->right) {
                child.node = info.node->right;
            }
            q.push(child);
        }
    }

    std::cout <<std::endl;

    return;
}

int main() {
    while (1) {
        std::cout << "Number of elements in the BST (Ctrl-C to exit):" << std::endl;
        int n;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " integers:" << std::endl;

        std::vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int ele;
            std::cin >> ele;
            nums.emplace_back(ele);
        }

        std::sort(nums.begin(), nums.end());

        std::cout << "Input k: " << std::endl;
        int k;
        std::cin >> k;

        auto tree = createBinarySearchTreeFromSortedVec(nums, 0, nums.size() - 1);
        printTree(tree);

        Solution solution;
        auto ret = solution.kthSmallest(tree, k);
        std::cout << ret << std::endl;
    }
}

