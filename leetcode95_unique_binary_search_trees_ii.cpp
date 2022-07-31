/**
 * @file leetcode95_unique_binary_search_trees_ii.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2022/07/31 15:44:56
 * @brief https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    std::vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode*> result_trees = _generate_trees(1, n);

        return result_trees;
    }

private:
    std::vector<TreeNode*> _generate_trees(int lo, int hi) {
        std::vector<TreeNode*> result_trees;

        if (lo > hi) {
            result_trees.push_back(nullptr);
            return result_trees;
        }

        for(int i = lo; i <= hi; ++i) {
            std::vector<TreeNode*> left_trees = _generate_trees(lo, i - 1);
            std::vector<TreeNode*> right_trees = _generate_trees(i + 1, hi);

            for (size_t j = 0; j < left_trees.size(); ++j) {

                for (size_t k = 0; k < right_trees.size(); ++k) {
                    TreeNode* root = new TreeNode(i);

                    root->left = left_trees[j];
                    root->right = right_trees[k];

                    result_trees.push_back(root);
                }
            }
        }

        return result_trees;
    }
};

void pre_order_traversal(TreeNode* root) {
    if (!root) {
        return;
    }

    std::cout << root->val << " ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);

    return;
}

int main() {
    while (1) {
        std::cout << "Number n (0 or less to exit):";
        int n;
        std::cin >> n;
        if (n <= 0) {
            return 0;
        }

        Solution solution;
        auto ret = solution.generateTrees(n);

        for (auto root: ret) {
            std::cout << "[";
            pre_order_traversal(root);
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
