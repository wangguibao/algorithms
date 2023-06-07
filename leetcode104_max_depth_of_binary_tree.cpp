/**
 * @file leetcode104_max_depth_of_binary_tree.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/07 19:35
 * @brief https://leetcode.com/problems/maximum-depth-of-binary-tree
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

TreeNode* construct_tree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    auto right = root->right;
    right->left = new TreeNode(3);
    right->right = new TreeNode(6);
    return root;
}

void print_tree(TreeNode* root) {
    std::queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        std::cout << node->val << " ";
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }

    std::cout << std::endl;
}

int main() {
    TreeNode* root = construct_tree();

    Solution solution;
    auto ret = solution.maxDepth(root);

    std::cout << ret << std::endl;
    return 0;
}
