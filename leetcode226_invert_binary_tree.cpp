/**
 * @file leetcode226_invert_binary_tree.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/05 09:39:05
 * @brief https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);

        return root;
    }
};

TreeNode* construct_tree() {
#if 0
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    auto right = root->right;
    right->left = new TreeNode(3);
    right->right = new TreeNode(6);
#else
    TreeNode* root = new TreeNode(2147483647);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
#endif
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
    auto ret = solution.invertTree(root);

    print_tree(ret);
    return 0;
}
