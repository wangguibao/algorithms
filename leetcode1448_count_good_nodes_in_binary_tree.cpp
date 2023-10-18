/**
 * @file leetcode1448_count_good_nodes_in_binary_tree.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/10/18 17:28
 * @brief https://leetcode.com/problems/count-good-nodes-in-binary-tree
 *
 **/
#include <iostream>
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
    int goodNodes(TreeNode* root) {
        return goodNodesInChildren(root, root->val);
    }
private:
    int goodNodesInChildren(TreeNode* root, int upperLevelMax) {
        if (!root) {
            return 0;
        }

        int n = 0;
        if (root->val >= upperLevelMax) {
            n++;
        }
        int maxValue = std::max(root->val, upperLevelMax);
        n += goodNodesInChildren(root->left, maxValue);
        n += goodNodesInChildren(root->right, maxValue);

        return n;
    }
};

TreeNode* constructTree() {
#if 0
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    auto left = root->left;
    left->left = new TreeNode(3);

    auto right = root->right;
    right->left = new TreeNode(1);
    right->right = new TreeNode(5);
#else
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(3);

    TreeNode* left = root->left;
    left->left = new TreeNode(4);
    left->right = new TreeNode(2);
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
    TreeNode* root = constructTree();
    printTree(root);

    Solution solution;
    int n = solution.goodNodes(root);

    std::cout << n << std::endl;
    return 0;
}
