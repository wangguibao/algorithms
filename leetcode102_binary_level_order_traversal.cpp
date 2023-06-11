/**
 * @file leetcode102_binary_tree_level_order_traversal.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/11 09:03
 * @brief https://leetcode.com/problems/binary-tree-level-order-traversal
 *
 **/
#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;

        if (root == nullptr) {
            return ret;
        }

        std::vector<NodeInfo> nodeVec;
        std::queue<NodeInfo> q;

        NodeInfo info;
        info.node = root;
        info.level = 0;
        q.push(info);

        while (!q.empty()) {
            auto info = q.front();
            q.pop();

            nodeVec.emplace_back(info);

            if (info.node->left) {
                NodeInfo leftNode;
                leftNode.node = info.node->left;
                leftNode.level = info.level + 1;
                q.push(leftNode);
            }

            if (info.node->right) {
                NodeInfo rightNode;
                rightNode.node = info.node->right;
                rightNode.level = info.level + 1;
                q.push(rightNode);
            }
        }

        size_t size = nodeVec.size();

        size_t i = 0;
        int level = nodeVec[0].level;
        std::vector<int> levelVec;
        levelVec.push_back(nodeVec[0].node->val);

        for (i = 1; i < size; ++i) {
            if (nodeVec[i].level != level) {
                ret.push_back(levelVec);
                levelVec.clear();
                level = nodeVec[i].level;
            }
            levelVec.push_back(nodeVec[i].node->val);
        }

        ret.push_back(levelVec);
        return ret;
    }

private:
    struct NodeInfo {
        TreeNode* node;
        int level;
    };
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
    auto ret = solution.levelOrder(root);

    for (size_t i = 0; i < ret.size(); ++i) {
        std::cout << "{";
        for (size_t j = 0; j < ret[i].size(); ++j) {
            std::cout << ret[i][j] << " ";
        }
        std::cout << "}" << std::endl;
    }
    return 0;
}
