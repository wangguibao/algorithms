/**
 * @file leetcode98_validate_binary_search_tree.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/08/04 11:15:25
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
        int64_t min_ele;
        int64_t max_ele;

        return _is_valid_bst(root, min_ele, max_ele);
    }

private:
    bool _is_valid_bst(TreeNode* root, int64_t& min_ele, int64_t& max_ele) {
        if (root == nullptr) {
            min_ele = LLONG_MAX;
            max_ele = LLONG_MIN;
            return true;
        }

        int64_t left_min = 0;
        int64_t left_max = 0;
        bool valid = _is_valid_bst(root->left, left_min, left_max);
        if (!valid) {
            return false;
        }

        if (left_max >= root->val) {
            return false;
        }

        int64_t right_min = 0;
        int64_t right_max = 0;
        valid = _is_valid_bst(root->right, right_min, right_max);
        if (!valid) {
            return false;
        }

        if (right_min <= root->val) {
            return false;
        }

        min_ele = std::min(left_min, static_cast<int64_t>(root->val));
        max_ele = std::max(right_max, static_cast<int64_t>(root->val));
        return true;
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
    //root->left = new TreeNode(1);
    //root->right = new TreeNode(3);
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
