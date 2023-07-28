/**
 * @file leetcode100_same_tree.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/07/28 10:37
 * @brief https://leetcode.com/problems/same-tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return (p == nullptr && q == nullptr);
        }
    }
};

TreeNode* constructTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    auto left = root->left;
    left->right = new TreeNode(4);

    auto right = root->right;
    right->right = new TreeNode(4);

    return root;
}

TreeNode* constructTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    auto left = root->left;
    left->right = new TreeNode(4);

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

void printTree(TreeNode* root) {
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
    TreeNode* tree1 = constructTree1();
    printTree(tree1);

    TreeNode* tree2 = constructTree2();
    printTree(tree2);

    Solution solution;
    bool same = solution.isSameTree(tree1, tree2);

    std::string str = same ? std::string("true") : std::string("false");
    std::cout << str << std::endl;
    return 0;
}
