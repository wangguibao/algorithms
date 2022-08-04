/**
 * @file leetcode98_validate_binary_search_tree_II.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/04 11:58:23
 * @brief https://leetcode.com/problems/validate-binary-search-tree/
 *
 **/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

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
    bool isValidBST(TreeNode* root) {
        /*
         * Key point: in order traversal
         * If the tree is a valid BST, then the result is strictly ascending
         *
         */
        std::vector<int> result;
        inOrderTraversal(root, result);

        for (size_t i = 0; i < result.size() - 1; ++i) {
            if (result[i] >= result[i+1]) {
                return false;
            }
        }

        return true;
    }

private:
    void inOrderTraversal(TreeNode* root, std::vector<int>& result) {
        if (!root) {
            return;
        }

        inOrderTraversal(root->left, result);
        result.push_back(root->val);
        inOrderTraversal(root->right, result);

        return;
    }
};

TreeNode* construct_tree() {
#if 1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    auto right = root->right;
    right->left = new TreeNode(3);
    right->right = new TreeNode(6);
#else
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
#endif
    return root;
}

int main() {
    TreeNode* root = construct_tree();

    Solution solution;
    auto ret = solution.isValidBST(root);

    if (ret) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    return 0;
}
