/**
 * @file leetcode94_binary_tree_inorder_traversal_02_iterative.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/10 11:58:36
 * @brief https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result_vec;
        std::stack<TreeNode*> st;

        TreeNode* p = root;
        while (p || !st.empty()) {
            if (p) {
                while (p) {
                    st.push(p);
                    p = p->left;
                }
            }else {
                p = st.top();
                result_vec.push_back(p->val);
                st.pop();

                p = p->right;
            }
        }

        return result_vec;
    }
};

TreeNode* construct_tree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    return root;
}

int main() {
    Solution solution;
    auto root = construct_tree();
    auto ret = solution.inorderTraversal(root);

    for (auto x: ret) {
        std::cout << x << ",";
    }
    std::cout << std::endl;
    return 0;
}
