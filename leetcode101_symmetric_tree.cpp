/**
 * @file leetcode101_symmetric_tree.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/05/24 21:18
 * @brief https://leetcode.com/problems/symmetric-tree/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
    bool isSymmeric(TreeNode* root) {
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;

        if (root == nullptr) {
            return true;
        }

        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty()) {
            auto ele1 = q1.front();
            q1.pop();

            auto ele2 = q2.front();
            q2.pop();

            if (ele1 == nullptr && ele2 != nullptr) {
                return false;
            }

            if (ele1 != nullptr && ele2 == nullptr) {
                return false;
            }

            if (ele1  && ele2 && ele1->val != ele2->val) {
                return false;
            }

            if (ele1) {
                q1.push(ele1->left);
                q1.push(ele1->right);
            }

            if (ele2) {
                q2.push(ele2->right);
                q2.push(ele2->left);
            }
        }

        if (q1.empty() && !q2.empty()) {
            return false;
        }

        if (!q1.empty() && q2.empty()) {
            return false;
        }

        return true;
    }

};

TreeNode* construct_tree() {
#if 1
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    auto left = root->left;
    left->right = new TreeNode(4);

    auto right = root->right;
    right->right = new TreeNode(4);
#else
    TreeNode* root = new TreeNode(2147483647);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
#endif
    return root;
}

struct LevelNode {
    TreeNode* node;
    int left_or_right;
    int level;

    LevelNode(TreeNode* node, int level, int left_or_right) {
        this->node = node;
        this->level = level;
        this->left_or_right = left_or_right;
    }
};

void print_tree(TreeNode* root) {
    std::queue<LevelNode> q;

    q.emplace(root, 0, 0);

    int current_level = 0;
    while (!q.empty()) {
        LevelNode level_node = q.front();
        q.pop();

        if (level_node.level != current_level) {
            std::cout << std::endl;
            current_level = level_node.level;
        }

        if (level_node.left_or_right == 1) {
            std::cout << " - ";
        }

        if (level_node.node == nullptr) {
            std::cout << "N";
        } else {
            std::cout << level_node.node->val;
        }

        if (level_node.left_or_right == 1) {
            std::cout << " ";
        }

        if (level_node.node) {
            q.emplace(level_node.node->left, level_node.level + 1, 0);
            q.emplace(level_node.node->right, level_node.level + 1, 1);
        }
    }

    std::cout << std::endl;
}

int main() {
    TreeNode* root = construct_tree();
    print_tree(root);

    Solution solution;
    bool symmetric = solution.isSymmeric(root);

    std::string str = symmetric ? std::string("true") : std::string("false");
    std::cout << str << std::endl;
    return 0;
}
